/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Component
*/

#include <stdlib.h>
#include "Component.h"
#include "Log.h"

static OmComponent *OmComponent_Create(void)
{
    return ((OmComponent *)malloc(sizeof(OmComponent)));
}

static void OmComponent_Destroy(OmComponent *item)
{
    OmComponent *tmp = 0;

    item->Parent = 0;
    if (item->Child == 0)
        return;
    OmVectorS->Drop(item->Child);
    OmVectorS->Clear(item->StateMap, true);
    OmVectorS->Drop(item->StateMap);
    OmVectorS->Drop(item->Observers);
}

static OmComponent *OmComponent_Init(OmComponent *item, OmComponent *Parent)
{
    if (Parent)
        item->DeltaOrder = Parent->DeltaOrder + 100;
    else
        item->DeltaOrder = 100;
    item->isActive = true;
    item->Order = 0;
    item->Parent = Parent;
    item->Child = OmVectorS->With_Capacity(1);
    item->StateMap = OmVectorS->With_Capacity(1);
    item->defState = OmComponentS->AddState(item, OmComponentState_Default, 0, 0, 0);
    item->curState = item->defState;
    item->preState = item->defState;
    item->Observers = 0;
    return (item);
}

static OmComponent *OmComponent_Append_Child(OmComponent *item, OmComponent *Child)
{
    if (!Child)
        return (0);
    OmVectorS->Push_back(item->Child, 1, Child);
    return (Child);
}

static OmComponent *OmComponent_Add_Child(OmComponent *item, OmComponent *Child, size_t order)
{
    if (!Child)
        return (0);
    if (OmVectorS->Set(item->Child, order, Child))
        return (Child);
    else
        return (0);
}

static OmComponent *OmComponent_Remove_Child(OmComponent *item, size_t index)
{
    OmComponent *tmp = OmVectorS->Remove(item->Child, index);

    return ((tmp) ? tmp : 0);
}

static OmComponent *OmComponent_Get_Child(OmComponent *item, size_t index)
{
    OmComponent *tmp = OmVectorS->At(item->Child, index);

    return ((tmp) ? tmp : 0);
}

static int OmComponent_Sorter(void *a, size_t idx1, void *b, size_t idx2)
{
    OmComponent *a1 = a;
    OmComponent *b1 = b;

    (void)idx1;
    (void)idx2;
    if (a1->Order < b1->Order)
        return (1);
    else
        return (0);
}

static OmComponent *OmComponent_Order_Child(OmComponent *item,
        int (* const predicate)(void *a, size_t idx1, void *b, size_t idx2))
{
    if (predicate == 0) {
        OmVectorS->Sort(item->Child, OmComponent_Sorter);
    } else {
        OmVectorS->Sort(item->Child, predicate);
    }
    return (item);
}

static void OmComponent_AddObserver(OmComponent *item, OmComponent *observer)
{
    OmLog_((item == 0 || observer == 0), LTAG_WARNING,
        "OmComponent AddObserver : item and observer can't be NULL\n", 0);
    if (item->Observers == 0)
        item->Observers = OmVectorS->With_Capacity(2);
    OmLog_((item->Observers == 0), LTAG_WARNING,
        "OmComponentAddObserver : Couldn't create OmVector\n", 0);
    OmVectorS->Push_back(item->Observers, 1, observer);
}

static bool OmComponent_FindObserver(void *context, void *elem, size_t idx)
{
    (void)idx;

    if (context == elem)
        return (true);
    else
        return (false);
}

static void OmComponent_RemoveObserver(OmComponent *item, OmComponent *observer)
{
    ssize_t idx = 0;

    OmLog_((item != 0 || observer != 0), LTAG_WARNING,
        "OmComponent RemoveObserver : item and observer can't be NULL\n", 0);
    OmLog_((item->Observers != 0), LTAG_WARNING,
        "OmComponent RemoveObserve : Observers OmVector is NULL\n", 0);
    if (item->Observers != 0)
        idx = OmVectorS->Find_index(item->Observers,
                &OmComponent_FindObserver, observer);
    OmLog_((item->Observers != 0), LTAG_INFO,
        "OmComponent RemoveObserve : Couldn't find observer\n", 0);
    if (idx != -1)
        OmVectorS->Remove(item->Observers, idx);
}

static bool OmComponent_SendMessage(OmComponent *item, void *sender, int subject, void *extraData)
{
    if (item->isActive) {
        if (item->curState->OnMessage != 0 && item->curState->OnMessage(item, sender, subject, extraData))
            return (true);
        for (size_t i = 0; i < item->Child->size; i++) {
            if (OmComponentS->SendMessage(item->Child->data[i], sender, subject, extraData))
                return (true);
        }
    }
    return (false);
}

static void OmComponent_Notify(OmComponent *sender, int subject, void *extraData)
{
    OmComponent *tmp = 0;

    OmLog_(sender != 0, LTAG_WARNING,
        "AComponent Notify failed, sender can't be NULL\n", 0);
    if (sender->isActive) {
        for (int i = 0; i < sender->Observers->size; i++) {
            tmp = sender->Observers->data[i];
            if (tmp->isActive && tmp->curState->OnMessage
                && tmp->curState->OnMessage(tmp, sender, subject, extraData))
                break;
        }
    }
}

static bool OmComponentState_Find(void *context, void *elem, size_t idx)
{
    OmComponentState *tmp = elem;
    int *stateID = context;

    if (tmp->ID == *stateID)
        return (true);
    else
        return (false);
}

static void OmComponent_SetState(OmComponent *item, int stateID)
{
    OmComponentState *st;

    if (item->isActive) {
        st = OmVectorS->Find(item->Observers, OmComponentState_Find, &stateID);
        OmLog_(st != 0, LTAG_WARNING,
            "OmComponent SetState failed : couldn't find stateID = %d\n", stateID);
        if (item->curState->OnMessage)
            item->curState->OnMessage(item, OmComponentS, ComponentMsg_OnExit, 0);
        item->preState = item->curState;
        item->curState = st;
        if (st->OnMessage)
            st->OnMessage(item, OmComponentS, ComponentMsg_OnEnter, NULL);
    }
}

static OmComponentState *OmComponent_AddState(OmComponent *item, int stateID,
    OmComponent_StateOnMessage OnMessage, OmComponent_StateUpdate Update, OmComponent_Render *Render)
{
    OmComponentState *state = 0;

    OmLog_(item != 0, LTAG_WARNING, "OmComponent AddState failed : item can't be NULL\n", 0);
    state = malloc(sizeof(OmComponentState));
    OmLog_(state != 0, LTAG_ERROR, "OmComponent AddState failed : malloc failed\n", 0);
    state->ID = stateID;
    state->Update = Update;
    state->UpdateAfter = 0;
    state->OnMessage = OnMessage;
    state->Render = 0;
    OmVectorS->Push_back(item->StateMap, 1, state);
    return (state);
}

static void OmComponent_SetActive(OmComponent *item, bool isActive)
{
    OmComponent *tmp = 0;

    item->isActive = isActive;
    for (int i = 0; i < item->Child->size; i++) {
        tmp = item->Child->data[i];
        tmp->isActive = isActive;
    }
}

static void OmComponent_Update(OmComponent *item, float DeltaTime)
{
    if (item->isActive) {
        if (item->curState->Update)
            item->curState->Update(item, DeltaTime);
    }
    for (int i = 0; i < item->Child->size; i++) {
        OmComponentS->Update(item->Child->data[i], DeltaTime);
    }
    if (item->curState->UpdateAfter)
        item->curState->UpdateAfter(item, DeltaTime);
}

struct _OmComponent OmComponentS[1] =
{
    {
        OmComponent_Create,
        OmComponent_Destroy,
        OmComponent_Init,
        OmComponent_Append_Child,
        OmComponent_Add_Child,
        OmComponent_Remove_Child,
        OmComponent_Get_Child,
        OmComponent_Order_Child,
        OmComponent_AddObserver,
        OmComponent_RemoveObserver,
        OmComponent_SendMessage,
        OmComponent_Notify,
        OmComponent_SetState,
        OmComponent_AddState,
        OmComponent_SetActive,
        OmComponent_Update
    }
};
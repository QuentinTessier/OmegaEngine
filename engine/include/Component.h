/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmComponent
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "DataStruct/Vector.h"


/*
-- Component => Base engine item, build a tree out of the game data
*/
typedef struct OmComponent OmComponent;

/*
-- Component State => Update Methods and Event Handling
*/
typedef struct OmComponentState OmComponentState;

struct OmComponentState {
    /*
    --  Key value in the StateMap
    */
    int ID;
    /*
    --  Update methods called every frame if Component is active
    */
    void (* Update)(OmComponent *item, float DeltaTime);
    /*
    --  Update Child first then the Component
    */
    void (* UpdateAfter)(OmComponent *item, float DeltaTime);
    /*
    -- Called when a Event is passed throw the game
    */
    void (* OnEvent)(OmComponent *item, sfEvent event);
    /*
    -- Called when a Message is received
    */
    bool (* OnMessage)(OmComponent *item, void *sender, int subject, void *extraData);
};

typedef enum ComponentMsg {
    ComponentMsg_OnExit,
    ComponentMsg_OnEnter
};

#define OmComponentState_Default 0

struct OmComponent {
    bool isActive;

    int Order;
    int DeltaOrder;

    struct OmComponent *Parent;
    OmVector *Child;

    OmComponentState *curState;
    OmComponentState *preState;
    OmComponentState *defState;
    OmVector *StateMap;
    OmVector *Observers;
};

/*
-- Declaration of a State.Update
*/
typedef void (* OmComponent_StateUpdate)(OmComponent *item, float DeltaTime);
typedef bool (* OmComponent_StateOnMessage)(OmComponent *item, void *sender, int subject, void *extraData);

struct _OmComponent {
    /*
    -- Allocate memory for a Component
    */
    OmComponent *(* const Create)(void);
    /*
    -- Release memory using the destroy callback
    */
    void (* const Destroy)(OmComponent *item, bool free_child);
    /*
    -- Init data inside the Component
    */
    OmComponent *(* const Init)(OmComponent *item, OmComponent *Parent);
    /*
    -- Add a child at the end of the Vector
    */
    OmComponent *(* const Append_Child)(OmComponent *item, OmComponent *Child);
    /*
    -- Add a child in the Vector following the order
    */
    OmComponent *(* const Add_Child)(OmComponent *item, OmComponent *Child, size_t order);
    /*
    -- Remove a child for the Vector
    */
    OmComponent *(* const Remove_Child)(OmComponent *item, size_t index);
    /*
    -- Returns a child  for the Vector
    */
    OmComponent *(* const Get_Child)(OmComponent *item, size_t index);
    /*
    -- Sort all child following the order
    */
    OmComponent *(* const Order_Child)(OmComponent *item,
            int (* const predicate)(void *a, size_t idxa, void *b, size_t idxb));
    /*
    -- Add observe to sender
    */
    void (* const AddObserver)(OmComponent *item, OmComponent *observer);
    /*
    -- Remove observer from sender
    */
    void (* const RemoveObserver)(OmComponent *item, OmComponent *observer);
    /*
    -- Call self and children's State.OnMessage
    -- If return true => consumed event then will stop event pass
    */
    bool (* const SendMessage)(OmComponent *item, void *sender, int subject, void *extraData);
    /*
    -- Notify sender all observer's State.OnMessage
    */
    void (* const Notify)(OmComponent *item, int subject, void *extraData);
    /*
    -- Change current active State
    */
    void (* const SetState)(OmComponent *item, int StateID);
    /*
    -- Add a state to the Component
    */
    OmComponentState *(* const AddState)(OmComponent *item, int StateID,
        OmComponent_StateOnMessage OnMessage, OmComponent_StateUpdate Update);
    /*
    -- Set Component active state
    */
    void (* const SetActive)(OmComponent *item, bool isActive);
    /*
    -- Call self and children's State.Update
    */
    void (* const Update)(OmComponent *item, float DeltaTime);
};

/*
-- OmComponentS => Contain every functions related to Component intern behaviors
*/
extern struct _OmComponent OmComponentS[1];
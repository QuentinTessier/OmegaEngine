/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** render
*/

#ifndef RENDER_H_
	#define RENDER_H_

void render_tab_sfRectangle(size_t length, sfRenderWindow *window, sfRectangleShape **shape);
void render_tab_sfSprite(size_t length, sfRenderWindow *window, sfSprite **sprite);

#define RD_SFT_RS(a, b, c) (render_tab_sfRectangle(a, b, c))
#define RD_SFT_CIS(a, b, c) (render_tab_sfCircleShape(a, b, c))
#define RD_SFT_SH(a, b, c) (render_tab_sfShape(a, b, c))
#define RD_SFT_TE(a, b, c) (render_tab_sfText(a, b, c))
#define RD_SFT_COS(a, b, c) (render_tab_sfConvexShape(a, b, c))
#define RD_SFT_VA(a, b, c) (render_tab_sfVertexArray(a, b, c))
#define RD_SFT_SP(a, b, c) (render_tab_sfSprite(a, b, c))
#define RD_SFT_SP_ST(a, b, c) (render_tab_struct(a, b, c))


#endif /* !RENDER_H_ */

#ifndef UI_H
#define UI_H

typedef struct{
    int padding;
} UI_context;

void UI_Context_init(UI_context* ui);
void UI_Context_update(UI_context* ui);
void UI_Context_draw(UI_context* ui);
void UI_Context_unload(UI_context* ui);

#endif
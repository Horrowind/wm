#ifndef DRAW_LIST_H
#define DRAW_LIST_H

#include "pool.h"
#include "stack.h"
#include "geometry.h"


typedef struct {
    enum {
        draw_cmd_quads;
        draw_cmd_triangles;
    } type;
    unsigned int elem_count;
    rect_t clip_rect;
    texture_id_t tex_id;
} draw_cmd_t;

typedef struct {
    fvec2_t pos;
    fvec2_t uv;
    u32     color;
} draw_vertex_t;

typedef u32 draw_idx;

typedef struct {
    pool_t cmd_buffer;
    pool_t idx_buffer;
    pool_t vtx_buffer;
    stack_t(rect_t) clip_rects;
    stack_t(texture_id_t) tex_ids;

    draw_idx current_draw_idx;
} draw_list_t;

void draw_list_init();
void draw_list_render();

void add_rectangle(draw_list_t* draw_list, rect_t rect, u32 color) {
    draw_cmd_t* idxs = pool_alloc(&draw_list->idx_buffer, 4);
    draw_cmd_t* vtxs = pool_alloc(&draw_list->vtx_buffer, 4);
    for(int i = 0; i < 4; i++) {
        idxs[i] = draw_list->current_draw_idx++;
    }
    fvec2 uv = fvec2_create(0, 0);
    
}


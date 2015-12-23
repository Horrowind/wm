#include <assert.h>

// OpenGL headers
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>
// SDL headers
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "geometry.h"

unsigned char zfont_bin[] = { 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04,
  0x00, 0x04, 0x12, 0x09, 0x00, 0x00, 0x00, 0x0a, 0x1f, 0x0a, 0x1f, 0x0a,
  0x1e, 0x05, 0x0e, 0x14, 0x0f, 0x11, 0x08, 0x04, 0x02, 0x11, 0x06, 0x19,
  0x0e, 0x19, 0x16, 0x04, 0x02, 0x00, 0x00, 0x00, 0x0c, 0x02, 0x02, 0x02,
  0x0c, 0x06, 0x08, 0x08, 0x08, 0x06, 0x15, 0x0e, 0x1f, 0x0e, 0x15, 0x04,
  0x04, 0x1f, 0x04, 0x04, 0x00, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x10, 0x08, 0x04, 0x02, 0x01,
  0x0e, 0x19, 0x15, 0x13, 0x0e, 0x04, 0x06, 0x04, 0x04, 0x0e, 0x0e, 0x11,
  0x0c, 0x02, 0x1f, 0x0e, 0x11, 0x0c, 0x11, 0x0e, 0x0a, 0x09, 0x1f, 0x08,
  0x08, 0x1f, 0x01, 0x0f, 0x10, 0x0f, 0x0e, 0x01, 0x0f, 0x11, 0x0e, 0x1f,
  0x10, 0x08, 0x08, 0x08, 0x0e, 0x11, 0x0e, 0x11, 0x0e, 0x0e, 0x11, 0x1e,
  0x10, 0x0e, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x04, 0x02,
  0x08, 0x04, 0x02, 0x04, 0x08, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x02, 0x04,
  0x08, 0x04, 0x02, 0x0e, 0x11, 0x0c, 0x00, 0x04, 0x0e, 0x19, 0x1d, 0x01,
  0x0e, 0x0e, 0x11, 0x1f, 0x11, 0x11, 0x0f, 0x11, 0x0f, 0x11, 0x0f, 0x0e,
  0x11, 0x01, 0x11, 0x0e, 0x0f, 0x11, 0x11, 0x11, 0x0f, 0x1f, 0x01, 0x0f,
  0x01, 0x1f, 0x1f, 0x01, 0x0f, 0x01, 0x01, 0x1e, 0x01, 0x19, 0x11, 0x0e,
  0x11, 0x11, 0x1f, 0x11, 0x11, 0x1f, 0x04, 0x04, 0x04, 0x1f, 0x1e, 0x08,
  0x08, 0x09, 0x06, 0x09, 0x05, 0x07, 0x09, 0x11, 0x01, 0x01, 0x01, 0x01,
  0x1f, 0x1b, 0x15, 0x15, 0x15, 0x11, 0x13, 0x15, 0x15, 0x15, 0x19, 0x0e,
  0x11, 0x11, 0x11, 0x0e, 0x0f, 0x11, 0x0f, 0x01, 0x01, 0x0e, 0x11, 0x15,
  0x09, 0x16, 0x0f, 0x11, 0x0f, 0x09, 0x11, 0x1e, 0x01, 0x0e, 0x10, 0x0f,
  0x1f, 0x04, 0x04, 0x04, 0x04, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x11, 0x11,
  0x0a, 0x0a, 0x04, 0x11, 0x15, 0x15, 0x15, 0x0a, 0x11, 0x0a, 0x04, 0x0a,
  0x11, 0x11, 0x0a, 0x04, 0x04, 0x04, 0x1f, 0x08, 0x04, 0x02, 0x1f, 0x0e,
  0x02, 0x02, 0x02, 0x0e, 0x01, 0x02, 0x04, 0x08, 0x10, 0x0e, 0x08, 0x08,
  0x08, 0x0e, 0x04, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,
  0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0c, 0x02, 0x03, 0x02, 0x0c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x06, 0x08, 0x18, 0x08, 0x06, 0x16, 0x09, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

GLuint font_texture;

typedef enum {
    split_none,
    split_horizontal,
    split_vertical,
} split_type_t;

typedef struct tiling_layout {
    split_type_t split_type;
    union {
        struct {
            float* splits;
            int num_splits;
            struct tiling_layout** sublayouts;
        };
        struct {
            float r, g, b;
        };
    };
} tiling_layout_t;

float lerp(float min, float max, float percentage) {
    return (max - min) * percentage + min;
}

typedef struct {
    fvec2_t pos;
    fvec2_t dpos;
    struct {
        int is_down_left : 1;
        int is_click_left : 1;
        int is_prev_down_left : 1;
        int is_down_right : 1;
        int is_click_right : 1;
        int is_prev_down_right : 1;
    };
} mouse_state_t;

typedef enum {
    action_none,
    action_split,
    action_close,
    action_drop
} action_type_t;

tiling_layout_t* dragging_data = NULL;

typedef struct {
    action_type_t type;
    union {
        struct {
            split_type_t split_type;
            tiling_layout_t* split_layout;
            tiling_layout_t* split_parent;
            int split_is_before;
        };
        struct {
            tiling_layout_t* close_layout;
            tiling_layout_t* close_parent;
        };
        struct {
            split_type_t drop_type;
            tiling_layout_t* drop_layout;
            tiling_layout_t* drop_parent;
            int drop_is_before;
        };
    };
} action_t;

void random_color(tiling_layout_t* layout) {
    layout->r = (float)rand() / (float)RAND_MAX;
    layout->g = (float)rand() / (float)RAND_MAX;
    layout->b = (float)rand() / (float)RAND_MAX;
}

void tiling_split(split_type_t split_type, tiling_layout_t* layout, tiling_layout_t* parent, int split_before) {
    if(parent == NULL || parent->split_type != split_type) {
        tiling_layout_t* new_layout = malloc(sizeof(tiling_layout_t));
        tiling_layout_t* old_layout_copy = malloc(sizeof(tiling_layout_t));
        memcpy(old_layout_copy, layout, sizeof(tiling_layout_t));
        new_layout->split_type = split_none;
        random_color(new_layout);
        layout->split_type = split_type;
        layout->num_splits = 1;
        layout->splits = malloc(sizeof(float));
        layout->splits[0] = 0.5;
        layout->sublayouts = malloc(2 * sizeof(tiling_layout_t*));
        layout->sublayouts[!split_before] = new_layout;
        layout->sublayouts[1 && split_before] = old_layout_copy;
    } else {
        float* new_splits = malloc((parent->num_splits + 1) * sizeof(float));
        tiling_layout_t** new_sublayouts = malloc((parent->num_splits + 2) * sizeof(tiling_layout_t));
        if(split_before) {
            int i = 0;
            for(int j = 0; j <= parent->num_splits; j++) {
                if(parent->sublayouts[j] == layout) {
                    if(j == 0) {
                        new_splits[0] = parent->splits[0] / 2;
                        new_sublayouts[0] = malloc(sizeof(tiling_layout_t));
                        new_sublayouts[0]->split_type = split_none;
                        random_color(new_sublayouts[0]);
                    } else if(j == parent->num_splits) {
                        new_splits[parent->num_splits] = (parent->splits[parent->num_splits - 1] + 1) / 2;
                        new_sublayouts[parent->num_splits] = malloc(sizeof(tiling_layout_t));
                        new_sublayouts[parent->num_splits]->split_type = split_none;
                        random_color(new_sublayouts[parent->num_splits]);
                    } else {
                        new_splits[j] = (parent->splits[i - 1] + parent->splits[i]) / 2;
                        new_sublayouts[j] = malloc(sizeof(tiling_layout_t));
                        new_sublayouts[j]->split_type = split_none;
                        random_color(new_sublayouts[j]);
                    }
                } else {
                    new_splits[j] = parent->splits[i];
                    new_sublayouts[j] = parent->sublayouts[i];
                    i++;
                }
            }
            new_sublayouts[parent->num_splits + 1] = parent->sublayouts[parent->num_splits];
        } else {
            new_sublayouts[0] = parent->sublayouts[0];
            int i = 0;
            for(int j = 0; j <= parent->num_splits; j++) {
                if(parent->sublayouts[j] == layout) {
                    if(j == 0) {
                        new_splits[0] = parent->splits[0] / 2;
                        new_sublayouts[1] = malloc(sizeof(tiling_layout_t));
                        new_sublayouts[1]->split_type = split_none;
                        random_color(new_sublayouts[1]);
                    } else if(j == parent->num_splits) {
                        new_splits[parent->num_splits] = (parent->splits[parent->num_splits - 1] + 1) / 2;
                        new_sublayouts[parent->num_splits + 1] = malloc(sizeof(tiling_layout_t));
                        new_sublayouts[parent->num_splits + 1]->split_type = split_none;
                        random_color(new_sublayouts[parent->num_splits + 1]);
                    } else {
                        new_splits[j] = (parent->splits[i - 1] + parent->splits[i]) / 2;
                        new_sublayouts[j + 1] = malloc(sizeof(tiling_layout_t));
                        new_sublayouts[j + 1]->split_type = split_none;
                        random_color(new_sublayouts[j + 1]);
                    }
                } else {
                    new_splits[j] = parent->splits[i];
                    new_sublayouts[j + 1] = parent->sublayouts[i + 1];
                    i++;
                }
            }
        }
        
        free(parent->splits);
        free(parent->sublayouts);
        parent->num_splits++;
        parent->splits = new_splits;
        parent->sublayouts = new_sublayouts;
    }
}    

void tiling_drop(split_type_t split_type, tiling_layout_t* layout, tiling_layout_t* parent, int split_before) {
    if(parent == NULL || parent->split_type != split_type) {
        tiling_layout_t* old_layout_copy = malloc(sizeof(tiling_layout_t));
        memcpy(old_layout_copy, layout, sizeof(tiling_layout_t));
        layout->split_type = split_type;
        layout->num_splits = 1;
        layout->splits = malloc(sizeof(float));
        layout->splits[0] = 0.5;
        layout->sublayouts = malloc(2 * sizeof(tiling_layout_t*));
        layout->sublayouts[!split_before] = dragging_data;
        dragging_data = NULL;
        layout->sublayouts[1 && split_before] = old_layout_copy;
    } else {
        float* new_splits = malloc((parent->num_splits + 1) * sizeof(float));
        tiling_layout_t** new_sublayouts = malloc((parent->num_splits + 2) * sizeof(tiling_layout_t));
        if(split_before) {
            int i = 0;
            for(int j = 0; j <= parent->num_splits; j++) {
                if(parent->sublayouts[j] == layout) {
                    if(j == 0) {
                        new_splits[0] = parent->splits[0] / 2;
                        new_sublayouts[0] = dragging_data;
                        dragging_data = NULL;
                    } else if(j == parent->num_splits) {
                        new_splits[parent->num_splits] = (parent->splits[parent->num_splits - 1] + 1) / 2;
                        new_sublayouts[parent->num_splits] = dragging_data;
                        dragging_data = NULL;
                    } else {
                        new_splits[j] = (parent->splits[i - 1] + parent->splits[i]) / 2;
                        new_sublayouts[j] = dragging_data;
                        dragging_data = NULL;
                    }
                } else {
                    new_splits[j] = parent->splits[i];
                    new_sublayouts[j] = parent->sublayouts[i];
                    i++;
                }
            }
            new_sublayouts[parent->num_splits + 1] = parent->sublayouts[parent->num_splits];
        } else {
            new_sublayouts[0] = parent->sublayouts[0];
            int i = 0;
            for(int j = 0; j <= parent->num_splits; j++) {
                if(parent->sublayouts[j] == layout) {
                    if(j == 0) {
                        new_splits[0] = parent->splits[0] / 2;
                        new_sublayouts[1] = dragging_data;
                        dragging_data = NULL;
                    } else if(j == parent->num_splits) {
                        new_splits[parent->num_splits] = (parent->splits[parent->num_splits - 1] + 1) / 2;
                        new_sublayouts[parent->num_splits + 1] = dragging_data;
                        dragging_data = NULL;
                    } else {
                        new_splits[j] = (parent->splits[i - 1] + parent->splits[i]) / 2;
                        new_sublayouts[j + 1] = dragging_data;
                        dragging_data = NULL;
                    }
                } else {
                    new_splits[j] = parent->splits[i];
                    new_sublayouts[j + 1] = parent->sublayouts[i + 1];
                    i++;
                }
            }
        }
        
        free(parent->splits);
        free(parent->sublayouts);
        parent->num_splits++;
        parent->splits = new_splits;
        parent->sublayouts = new_sublayouts;
    }
}    

void tiling_close(tiling_layout_t* layout, tiling_layout_t* parent) {
    if(parent->num_splits == 1) {
        if(parent->sublayouts[0] == layout) {
            free(layout);
            free(parent->splits);
            tiling_layout_t* tmp = parent->sublayouts[1];
            free(parent->sublayouts);
            memcpy(parent, tmp, sizeof(tiling_layout_t));
            free(tmp);
        } else {
            free(layout);
            free(parent->splits);
            tiling_layout_t* tmp = parent->sublayouts[0];
            free(parent->sublayouts);
            memcpy(parent, tmp, sizeof(tiling_layout_t));
            free(tmp);
        }
    } else {
        float* new_splits = malloc((parent->num_splits - 1) * sizeof(float));
        tiling_layout_t** new_sublayouts = malloc((parent->num_splits) * sizeof(tiling_layout_t));
        int j = 0;
        for(int i = 0; i < parent->num_splits; i++, j++) {
            if(layout == parent->sublayouts[j]) {
                if(j == 0) {
                    new_splits[0] = parent->splits[1];
                    new_sublayouts[0] = parent->sublayouts[1];
                    j++;
                } else {
                    new_splits[i - 1] = (parent->splits[j - 1] + parent->splits[j]) / 2;
                    new_splits[i] = parent->splits[j + 1];
                    new_sublayouts[i] = parent->sublayouts[j + 1];
                    j++;
                }
            } else {
                new_splits[i] = parent->splits[j];
                new_sublayouts[i] = parent->sublayouts[j];
            }
        }
        if(layout == parent->sublayouts[j]) {
            new_splits[parent->num_splits - 1] = (parent->splits[j - 1] + parent->splits[j]) / 2;
            new_sublayouts[parent->num_splits] = parent->sublayouts[j + 1];
            j++;
        }
        
        if(j == parent->num_splits - 1) {
            new_sublayouts[parent->num_splits - 1] = parent->sublayouts[parent->num_splits - 1];
        } else {
            new_sublayouts[parent->num_splits - 1] = parent->sublayouts[parent->num_splits];
        }
        free(parent->splits);
        free(parent->sublayouts);
        parent->num_splits--;
        parent->splits = new_splits;
        parent->sublayouts = new_sublayouts;
    }
}

int quit;

typedef struct {
    uint32_t is_clicked : 1;
    uint32_t is_down : 1;
} button_press_t;

uint32_t is_down(button_press_t status) {
    return status.is_down;
}

uint32_t is_clicked(button_press_t status) {
    return status.is_clicked;
}

button_press_t button(rect_t rect, mouse_state_t mouse_state) {
    button_press_t status = { 0 };
    if(rect_contains(rect, mouse_state.pos)) {
        glColor3f(0.6f, 0.6f, 0.6f);
        status.is_down = mouse_state.is_click_left;
        status.is_clicked = mouse_state.is_down_left && !mouse_state.is_prev_down_left;
    } else {
        glColor3f(0.4f, 0.4f, 0.4f);
    }
    glVertex2f(rect.xmin, rect.ymax);
    glVertex2f(rect.xmax, rect.ymax);
    glVertex2f(rect.xmax, rect.ymin);
    glVertex2f(rect.xmin, rect.ymin);
    return status;
}

action_t handle_layout(tiling_layout_t* layout, tiling_layout_t* parent, rect_t rect,
                       mouse_state_t mouse_state, float window_width, float window_height) {
    action_t result;
    result.type = action_none;
    if(layout->split_type == split_none) {
        glColor3f(layout->r, layout->g, layout->b);
        glVertex2f(rect.xmin, rect.ymax);
        glVertex2f(rect.xmax, rect.ymax);
        glVertex2f(rect.xmax, rect.ymin);
        glVertex2f(rect.xmin, rect.ymin);


        if(is_clicked(button(rect_create(rect.xmin, rect.xmax, rect.ymax - 32.0f / window_height, rect.ymax), mouse_state)) && parent) {
            result.type = action_close;
            result.close_layout = layout;
            result.close_parent = parent;
        }
        
        if(rect_contains(rect, mouse_state.pos)) {
            float midx = (rect.xmin + rect.xmax) / 2;
            float midy = (rect.ymin + rect.ymax) / 2;

            if(is_down(button(rect_create(midx - 64.0f / window_width,
                                          midx - 32.0f / window_width,
                                          midy - 16.0f / window_height,
                                          midy + 16.0f / window_height),
                              mouse_state))) {
                if(dragging_data != NULL) {
                    result.type = action_drop;
                    result.drop_type = split_horizontal;
                    result.drop_layout = layout;
                    result.drop_parent = parent;
                    result.drop_is_before = 1;
                } else {
                    result.type = action_split;
                    result.split_type = split_horizontal;
                    result.split_layout = layout;
                    result.split_parent = parent;
                    result.split_is_before = 1;
                }
            }

            if(is_down(button(rect_create(midx + 32.0f / window_width,
                                          midx + 64.0f / window_width,
                                          midy - 16.0f / window_height,
                                          midy + 16.0f / window_height),
                              mouse_state))) {
                if(dragging_data != NULL) {
                    result.type = action_drop;
                    result.drop_type = split_horizontal;
                    result.drop_layout = layout;
                    result.drop_parent = parent;
                    result.drop_is_before = 0;
                } else {
                    result.type = action_split;
                    result.split_type = split_horizontal;
                    result.split_layout = layout;
                    result.split_parent = parent;
                    result.split_is_before = 0;
                }
            }

            if(is_down(button(rect_create(midx - 16.0f / window_width,
                                          midx + 16.0f / window_width,
                                          midy - 64.0f / window_height,
                                          midy - 32.0f / window_height),
                              mouse_state))) {
                if(dragging_data != NULL) {
                    result.type = action_drop;
                    result.drop_type = split_vertical;
                    result.drop_layout = layout;
                    result.drop_parent = parent;
                    result.drop_is_before = 1;
                } else {
                    result.type = action_split;
                    result.split_type = split_vertical;
                    result.split_layout = layout;
                    result.split_parent = parent;
                    result.split_is_before = 1;
                }
            }
            
            if(is_down(button(rect_create(midx - 16.0f / window_width,
                                          midx + 16.0f / window_width,
                                          midy + 32.0f / window_height,
                                          midy + 64.0f / window_height),
                              mouse_state))) {
                if(dragging_data != NULL) {
                    result.type = action_drop;
                    result.drop_type = split_vertical;
                    result.drop_layout = layout;
                    result.drop_parent = parent;
                    result.drop_is_before = 0;
                } else {
                    result.type = action_split;
                    result.split_type = split_vertical;
                    result.split_layout = layout;
                    result.split_parent = parent;
                    result.split_is_before = 0;
                }
            }            
        }
    } else if(layout->split_type == split_vertical) {
        float div_down = rect.ymin;
        for(int i = 0; i < layout->num_splits; i++) {
            float div_up = lerp(rect.ymin, rect.ymax, layout->splits[i]);
            action_t tmp = handle_layout(layout->sublayouts[i], layout,
                                         rect_create(rect.xmin, rect.xmax, div_down, div_up),
                                         mouse_state, window_width, window_height);
            if(tmp.type != action_none) result = tmp;
            div_down = div_up;
        }
        action_t tmp = handle_layout(layout->sublayouts[layout->num_splits], layout,
                                     rect_create(rect.xmin, rect.xmax, div_down, rect.ymax),
                                     mouse_state, window_width, window_height);
        if(tmp.type != action_none) result = tmp;
    } else {
        assert(layout->split_type == split_horizontal);
        float div_left = rect.xmin;
        for(int i = 0; i < layout->num_splits; i++) {
            float div_right = lerp(rect.xmin, rect.xmax, layout->splits[i]);
            action_t tmp = handle_layout(layout->sublayouts[i], layout,
                                         rect_create(div_left, div_right, rect.ymin, rect.ymax),
                                         mouse_state, window_width, window_height);
            if(tmp.type != action_none) result = tmp;
            div_left = div_right;
        }
        action_t tmp = handle_layout(layout->sublayouts[layout->num_splits], layout,
                                     rect_create(div_left, rect.xmax, rect.ymin, rect.ymax),
                                     mouse_state, window_width, window_height);
        if(tmp.type != action_none) result = tmp;
    }
    return result;
}

void init_font() {

    uint8_t temp_bitmap[128*64];
    for(int i = 0; i < 128; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 8; k++) {
                int x = ((i & 0xF) << 3) + k;
                int y = ((i >> 4) << 3) + j + 2;
                temp_bitmap[y * 128 + x] = 0xFF * ((zfont_bin[i * 5 + j] >> k) & 1);
            }
        }
    }

    glGenTextures(1, &font_texture);
    glBindTexture(GL_TEXTURE_2D, font_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_INTENSITY, 128, 64, 0, GL_RED, GL_UNSIGNED_BYTE, temp_bitmap);
}

void render_text(float x, float y, char* text, float window_width, float window_height, int draw_shadow) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, font_texture);
    glBegin(GL_QUADS);
    float y_up = y + 20.0f / window_width;
    float x_offset = 4.0f / window_width;
    float y_offset = 4.0f / window_height;
    
    while(*text) {
        float x_new = x + 24.0f / window_width;
        if(*text < 128) {
            float u0 = 1.0 / 128.0 * ((((*text) & 15) << 3));
            float u1 = 1.0 / 128.0 * ((((*text) & 15) << 3) + 6);
            float v1 = 1.0 /  64.0 * ((((*text) >> 4) << 3) + 2);
            float v0 = 1.0 /  64.0 * ((((*text) >> 4) << 3) + 7);
            if(draw_shadow) {
                glColor3f(0.4f, 0.4f, 0.4f);
                glTexCoord2f(u0,v0); glVertex2f(x     + x_offset, y    - y_offset);
                glTexCoord2f(u1,v0); glVertex2f(x_new + x_offset, y    - y_offset);
                glTexCoord2f(u1,v1); glVertex2f(x_new + x_offset, y_up - y_offset);
                glTexCoord2f(u0,v1); glVertex2f(x     + x_offset, y_up - y_offset);
            }
            glColor3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(u0,v0); glVertex2f(x    , y);
            glTexCoord2f(u1,v0); glVertex2f(x_new, y);
            glTexCoord2f(u1,v1); glVertex2f(x_new, y_up);
            glTexCoord2f(u0,v1); glVertex2f(x    , y_up);
        }
        x = x_new;
        ++text;
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

SDL_Window* window;
SDL_GLContext glContext;
SDL_Event sdlEvent;

int main(int argc, char *argv[]) {
    quit = 0;
    int window_width, window_height;

    //Use OpenGL 3.1 core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    // Initialize video subsystem
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Display error message
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    } else {
        // Create window
        window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  1280, 1024, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if(window == NULL) {
            // Display error message
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return 0;
        }
        else {
            // Create OpenGL context
            glContext = SDL_GL_CreateContext(window);

            if(glContext == NULL) {
                // Display error message
                printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
                return 0;
            } else {
                // Initialize glew
                glewInit();
                SDL_GetWindowSize(window, &window_width, &window_height);
                glEnable(GL_SCISSOR_TEST);
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                init_font();
            }
        }
    }


    tiling_layout_t layout;
    layout.r = 1.0f;
    layout.g = 0.0f;
    layout.b = 0.0f;
    layout.split_type = split_none;

    mouse_state_t mouse_state;    
    
    // Game loop
    while (!quit) {
        while(SDL_PollEvent(&sdlEvent) != 0) {
            // Esc button is pressed
            if(sdlEvent.type == SDL_QUIT) {
                quit = 1;
            }
        }

        int mousexi, mouseyi;
        uint32_t mouse_state_sdl = SDL_GetMouseState(&mousexi, &mouseyi);
        mouse_state.pos.x = (2.0f * (float)(+mousexi) - (float)(window_width )) / (float)(window_width );
        mouse_state.pos.y = (2.0f * (float)(-mouseyi) + (float)(window_height)) / (float)(window_height);
        mouse_state.is_prev_down_left = mouse_state.is_down_left;
        mouse_state.is_prev_down_right = mouse_state.is_down_right;
        mouse_state.is_click_left = mouse_state.is_down_left && !(mouse_state_sdl & SDL_BUTTON(SDL_BUTTON_LEFT));
        mouse_state.is_click_right = mouse_state.is_down_right && !(mouse_state_sdl & SDL_BUTTON(SDL_BUTTON_RIGHT));
        mouse_state.is_down_left = 1 && (mouse_state_sdl & SDL_BUTTON(SDL_BUTTON_LEFT));
        mouse_state.is_down_right = 1 && (mouse_state_sdl & SDL_BUTTON(SDL_BUTTON_RIGHT));

        

        // Clear color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBegin(GL_QUADS);
        action_t action = handle_layout(&layout, NULL, rect_create(-1, 1, -1, 1),
                                        mouse_state, (float)window_width, (float)window_height);


        if(action.type == action_split) {
            tiling_split(action.split_type, action.split_layout, action.split_parent, action.split_is_before);
        } else if(action.type == action_close) {
            dragging_data = malloc(sizeof(tiling_layout_t));
            memcpy(dragging_data, action.close_layout, sizeof(tiling_layout_t));
            tiling_close(action.close_layout, action.close_parent);
        } else if(action.type == action_drop) {
            tiling_drop(action.split_type, action.split_layout, action.split_parent, action.split_is_before);
        }

        if(dragging_data != NULL) {
            glColor4f(dragging_data->r, dragging_data->g, dragging_data->b, 0.7);
            glVertex2f(mouse_state.pos.x - 256.0f / window_width, mouse_state.pos.y + 256.0f / window_height);
            glVertex2f(mouse_state.pos.x + 256.0f / window_width, mouse_state.pos.y + 256.0f / window_height);
            glVertex2f(mouse_state.pos.x + 256.0f / window_width, mouse_state.pos.y - 256.0f / window_height);
            glVertex2f(mouse_state.pos.x - 256.0f / window_width, mouse_state.pos.y - 256.0f / window_height);
        }

        
        if(!mouse_state.is_down_left) {
            free(dragging_data);
            dragging_data = NULL;
        }
        glEnd();
        render_text(-1, 0, "HUHU", window_width, window_height, 1);

        

        
        // Update window with OpenGL rendering
        SDL_GL_SwapWindow(window);
    }

    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}

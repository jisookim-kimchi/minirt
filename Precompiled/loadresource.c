#include "loadresource.h"

/*
    should be called first
    manage just only mesh and texture 
    (1)------(2)
     |      / |
     |    /   |
     |  /     |
    (0)------(3)
*/
// int load_resource(t_engine* engine)
// {
//     if (engine->mesh_count >= MAX_MESHES)
//         return 0;

//     t_mesh* quad_mesh = &engine->meshes[engine->mesh_count++];
//     float squareHalfSize = 0.5f;

//     quad_mesh->vertex_count = 4;
//     quad_mesh->index_count = 6;

//     quad_mesh->vertices[0] = (t_vec2){ -squareHalfSize, -squareHalfSize };
//     quad_mesh->vertices[1] = (t_vec2){ -squareHalfSize,  squareHalfSize };
//     quad_mesh->vertices[2] = (t_vec2){  squareHalfSize,  squareHalfSize };
//     quad_mesh->vertices[3] = (t_vec2){  squareHalfSize, -squareHalfSize };

//     // UV coordinates for selecting a small portion of the texture
//     quad_mesh->uvs[0] = (t_vec2){ 0.125f, 0.75f };
//     quad_mesh->uvs[1] = (t_vec2){ 0.125f, 0.875f };
//     quad_mesh->uvs[2] = (t_vec2){ 0.25f,  0.875f };
//     quad_mesh->uvs[3] = (t_vec2){ 0.25f,  0.75f };

//     int indices[6] = { 0, 2, 1, 0, 3, 2 };
//     memcpy(quad_mesh->indices, indices, sizeof(indices));

//     // Texture 생성
//     if (engine->texture_count >= MAX_TEXTURES) return 0;
//     t_texture* base_texture = &engine->textures[engine->texture_count++];
//     base_texture->path = strdup("CharacterTexturePath"); // 실제 경로 문자열
//     base_texture->initialized = 1;
//     if (!base_texture->initialized)
//     {
//         return 0;
//     }
//     return 1;
// }

/*
    manage just only object
    if there's many objects then we have to consider to make hash later. 
*/

// t_game_object* create_new_game_object(t_engine* engine, const char* name)
// {
//     if (engine->scene_count >= MAX_SCENE_OBJECTS)
//         return NULL;

//     //check duplicated name
//     int i = 0;
//     while (i < engine->scene_count)
//     {
//         if (strcmp(engine->scene[i].name, name) == 0)
//         {
//             assert(0 && "there is same object's name");
//             return NULL;
//         }
//         i++;
//     }
//     t_game_object* new_object = &engine->scene[engine->scene_count++];
//     strncpy(new_object->name, name, sizeof(new_object->name) - 1);
//     new_object->name[sizeof(new_object->name) - 1] = '\0';

//     return new_object;
// }

// int main() {
//     t_engine engine = { 0 };

//     if (!load_resource(&engine)) {
//         printf("Failed to load resources\n");
//         return -1;
//     }

//     t_game_object* obj = create_new_game_object(&engine, "obj");
//     if (obj == NULL) {
//         printf("Failed to create game object\n");
//         return -1;
//     }

//     printf("game object created: %s\n", obj->name);

//     return 0;
// }

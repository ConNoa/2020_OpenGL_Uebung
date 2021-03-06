#ifndef APPLICATION_SOLAR_HPP
#define APPLICATION_SOLAR_HPP

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include "scenegraph.hpp"
#include "node.hpp"
#include "pointlightnode.hpp"
#include "geometrynode.hpp"
#include "cameranode.hpp"
#include "model.hpp"

#define PI 3.1415926


// gpu representation of model
class ApplicationSolar : public Application {
  public:
    // allocate and initialize objects
    ApplicationSolar(std::string const& resource_path);
    // free allocated objects
    ~ApplicationSolar();
    // react to key input
    void keyCallback(int key, int action, int mods);
    //handle delta mouse movement input
    void mouseCallback(double pos_x, double pos_y);
    //handle resizing
    void resizeCallback(unsigned width, unsigned height);

    // draw all objects
    void render() const;
    void renderSolarsystem() const; //executes  renderPlanets() for Planets & Sun
    void renderPlanets(Geometrynode* gn) const;
    void renderStars() const;
    void renderOrbits() const;

    void renderSky() const;
    void renderFrameBuffer() const;


  protected:
    GLuint initTexObj(pixel_data tex_data_in);
    void initializeStars();
    void initializeOrbits();
    void initializeSkybox();


    void initializeLabels();

    void loadTextures();
    void initializeTextures();

    void initializeSkyBoxTex();
    void initializeFramebuffer();
    void initializePlanets();
    void initializeShaderPrograms();
    void initializeGeometry();
    void initializePointlights();

    // update uniform values
    void uploadUniforms();
    // upload projection matrix
    void uploadProjection(std::string const& object);
    // upload view matrix
    void uploadView(std::string const& object);


    // cpu representation of model
    model_object planet_object;
    model_object star_object;
    model_object orbit_object;
    model_object sky_object;

    Scenegraph scene;

    // camera transform matrix
    glm::fmat4 view_matrix_;
    // camera projection matrix
    glm::fmat4 projection_matrix_;

    model planet_model;
    model star_model;
    model orbit_model;
    model sky_model;

    GLfloat shader_mode;
    std::vector<Planet>solarsystem_planets_;

    std::vector<float> stars_;
    std::vector<float> orbits_;

    std::vector<std::string> Labels;

    std::vector<texture> planet_textures;
    std::vector<texture> skybox_textures;
    std::vector<texture_object>texture_obj_container;

    texture_object skybox_object;
    pixel_data sky_sphere_texture;


    model_object quad_object;

    model quad_model;
    glm::vec4 pp_mode;

    texture_object frame_buffer_object;
    texture_object frame_buffer_tex_obj;
    texture_object render_buffer_object;

};

#endif

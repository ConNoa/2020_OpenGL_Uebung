#ifndef SCENEGRAPH_HPP
#define SCENEGRAPH_HPP

#include <string>
#include "node.hpp"

using namespace std;



class Scenegraph{
  public:

    string              getName();
    void                setName(string);
    Node                getRoot();
    void                setRoot(Node);

    string              printGraph();


  private:

    Scenegraph();
    Scenegraph(std::string const& name);
    ~Scenegraph();

    string scene_name_;
    Node root_;

};

#endif

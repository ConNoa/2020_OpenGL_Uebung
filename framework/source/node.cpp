#include "node.hpp"


Node::Node():
    parent_{},
    children_{},
    name_{},
    path_{},
    depth_{},
    localTransform_{},
    worldTransform_{}
{}

Node::~Node() {
}


shared_ptr<Node> Node::getParent(){
    return parent_;
}

void Node::setParent(shared_ptr<Node> parent){
    parent_ = parent;
}

shared_ptr<Node> Node::getChildren(string name){
    for(auto const& child : this -> getChildrenList()){
        if(child -> getName() == name){
            return child;
        }
    }
    return nullptr;
}

std::list<std::shared_ptr<Node>> Node::getChildrenList(){
    return children_;
}

std::string Node::getName(){
    return name_;
}

std::string Node::getPath(){
    return path_;
}

int Node::getDepth(){
    return depth_;
}

mat4 Node::getLocalTransform(){
    return localTransform_;
}

void Node::setLocalTransform(mat4 local_transform_input){
    localTransform_ = matrix_in;
}

glm::mat4 Node::getWorldTransform(){
    return worldTransform_;
}

void Node::setWorldTransform(mat4 world_transf_input){
    worldTransform_ = matrix_in;
}

void Node::addChildren(shared_ptr<Node> child){
    children_.push_back(child);
}

shared_ptr<Node> Node::removeChildren(string name){
    shared_ptr<Node> child = getChildren(name);
    children_.remove(child);
    return child;
}

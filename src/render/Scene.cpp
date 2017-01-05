/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Scene.h"

namespace render{
    Scene::Scene()
{
	layers.resize(3);
}

Scene::~Scene()
{
	int i;
	for (i = 0; i < layers.size(); i++)
		delete layers[i];
	layers.clear();
}
		
int Scene::getWidth() const
{
	return width;
}

int Scene::getHeight() const
{
	return height;
}

int Scene::getLayerCount() const
{
	return layers.size();
}

Layer* Scene::getLayer(int ind) const
{
	return layers[ind];
}

void Scene::setLayer(int ind,Layer* layer)
{
		layers.insert(layers.begin() + ind,layer); 
}

void Scene::registerObservers(const state::State* s)
{
	//~ state::StateObserver::registerObserver
}

void Scene::unregisterObservers(const state::State* s)
{
	
}

void Scene::stateChanged(const state::StateEvent& e)
{
	//~ new ListEvent
}
};
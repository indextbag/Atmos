﻿#include <core/a3Scene.h>
#include <shapes/a3Shape.h>
#include <core/a3Ray.h>
#include <lights/a3Light.h>
#include <core/log/a3Log.h>
#include <accelerators/a3PrimitiveSet.h>

a3Scene::a3Scene()
{

}

// --!不做安全检查以提高效率
bool a3Scene::intersect(const a3Ray& ray, a3Intersection* intersection) const
{
    return primitiveSet->intersect(ray, intersection);
}

bool a3Scene::intersect(const a3Ray& ray) const
{
    return primitiveSet->intersect(ray);
}

bool a3Scene::addShape(a3Shape* shape)
{
    if(!check()) return false;

    return primitiveSet->addShape(shape);
}

bool a3Scene::addLight(a3Light* light)
{
    if(!light)
    {
        a3Log::error("空的形状对象指针%d\n", light);
        return false;
    }

    lights.push_back(light);
    return true;
}

a3Spectrum a3Scene::le(const a3Ray& ray) const
{
    a3Spectrum le;

    // 添加可能有的无限远区域光照
    for(auto l : lights)
        le += l->le(ray);

    return le;
}

bool a3Scene::check() const
{
    if(!primitiveSet)
    {
        a3Log::error("a3Scene::render()前primitiveSet: %d尚未分配指定\n", primitiveSet);
        return false;
    }

    return true;
}



 
﻿#include <lights/a3Light.h>
#include <core/a3Scene.h>

a3Light::a3Light(const t3Matrix4x4& lightToWorld, std::string name)
: lightToWorld(lightToWorld), worldToLight(lightToWorld.getInverse()), name(name)
{

}

a3Light::a3Light(std::string name):name(name)
{
    lightToWorld.makeIdentityMatrix();
    worldToLight.makeIdentityMatrix();
}

a3Light::~a3Light()
{

}

a3Spectrum a3Light::le(const a3Ray& ray) const
{
    return t3Vector3f::zero();
}

float a3Light::pdf(const t3Vector3f&p, const t3Vector3f& wi) const
{
    return 0.0f;
}

//a3Spectrum a3Light::sampleL()
//{
//    return t3Vector3f::zero();
//}

void a3VisibilityTester::setSegment(const t3Vector3f &p1, float eps1, const t3Vector3f &p2, float eps2)
{
    double dist = (t3Vector3d(p1) - t3Vector3d(p2)).length();
    ray = a3Ray(p1, (p2 - p1).getNormalized(), eps1, dist * (1.0 - eps2));
}

bool a3VisibilityTester::occluded(const a3Scene *scene) const
{
    return scene->intersect(ray);
}

void a3VisibilityTester::setRay(const t3Vector3f& p, const t3Vector3f& direction, float eps)
{
    ray = a3Ray(p, direction, eps, A3_INFINITY);
}
 
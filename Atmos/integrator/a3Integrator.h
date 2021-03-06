﻿#pragma once

#include <core/a3Spectrum.h>

class a3Ray;
class a3Scene;

class a3Integrator
{
public:
    a3Integrator() {}

    virtual ~a3Integrator() {}

    // Sample the incident radiance along a ray.
    virtual a3Spectrum Li(const a3Ray& ray, const a3Scene& scene) const = 0;

    // Controls the number of light/bsdf samples for direct illumination per camera hit point
    int numLightSamples, numBxdfSamples;
};
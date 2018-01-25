﻿#ifndef A3_BSDF_H
#define A3_BSDF_H

#include <textures/a3Texture.h>
#include <core/a3Spectrum.h>

class a3BSDFSamplingRecord;
class a3BSDF
{
public:
    a3BSDF();

    a3BSDF(a3Texture<a3Spectrum>* texture);

    virtual ~a3BSDF();

    // Evaluate the BSDF f(wi, wo)
    virtual a3Spectrum eval(const a3BSDFSamplingRecord& bRec) const = 0;

    // Sample the BSDF and return the importance weight
    virtual a3Spectrum sample(a3BSDFSamplingRecord& bRec) const = 0;

    //  Compute the probability of sampling wo (given wi)
    virtual float pdf(const a3BSDFSamplingRecord& bRec) const = 0;

    // if delta distribution
    virtual bool isDeltaDistribution() const = 0;

    std::string name;

    // reflectance on texture
    a3Texture<a3Spectrum>* reflectance;

    // material's relative index of refraction
    float eta;
};

#endif
 
#pragma once

#include <bsdf/a3BSDF.h>

class a3Conductor : public a3BSDF
{
public:
    a3Conductor();

    // evaluate the BSDF f(wi, wo)(f * cos * R)
    virtual a3Spectrum eval(const a3BSDFSamplingRecord& bRec) const;

    // sample the BSDF and return the importance weight
    // returned value has divided by the probability density of the sample
    virtual a3Spectrum sample(a3BSDFSamplingRecord& bRec) const;

    // compute the probability of sampling wo (given wi, BSDF(wi, wo) * costheta)
    virtual float pdf(const a3BSDFSamplingRecord& bRec) const;

    // if delta distribution
    virtual bool isDeltaDistribution() const;

    // specular refelctance
    a3Spectrum R;

    // interior refractive index of refraction, absorbtion
    a3Spectrum eta, k;
};
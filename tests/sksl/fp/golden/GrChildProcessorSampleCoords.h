

/**************************************************************************************************
 *** This file was autogenerated from GrChildProcessorSampleCoords.fp; do not modify.
 **************************************************************************************************/
#ifndef GrChildProcessorSampleCoords_DEFINED
#define GrChildProcessorSampleCoords_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"


#include "src/gpu/GrFragmentProcessor.h"

class GrChildProcessorSampleCoords : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(std::unique_ptr<GrFragmentProcessor> child) {
        return std::unique_ptr<GrFragmentProcessor>(new GrChildProcessorSampleCoords(std::move(child)));
    }
    GrChildProcessorSampleCoords(const GrChildProcessorSampleCoords& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "ChildProcessorSampleCoords"; }
private:
    GrChildProcessorSampleCoords(std::unique_ptr<GrFragmentProcessor> child)
    : INHERITED(kGrChildProcessorSampleCoords_ClassID, kNone_OptimizationFlags) {
        this->setUsesSampleCoordsDirectly();
        SkASSERT(child);        this->registerChild(std::move(child), SkSL::SampleUsage(SkSL::SampleUsage::Kind::kNone, "", false, true, true));    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
#if GR_TEST_UTILS
    SkString onDumpInfo() const override;
#endif
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    using INHERITED = GrFragmentProcessor;
};
#endif

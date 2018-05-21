/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkMagnifierImageFilter_DEFINED
#define SkMagnifierImageFilter_DEFINED

#include "SkRect.h"
#include "SkImageFilter.h"

class SK_API SkMagnifierImageFilter : public SkImageFilter {
public:
    static sk_sp<SkImageFilter> Make(const SkRect& srcRect, SkScalar inset,
                                     sk_sp<SkImageFilter> input,
                                     const CropRect* cropRect = nullptr);

    void toString(SkString* str) const override;

    Factory getFactory() const override { return CreateProc; }

protected:
    SkMagnifierImageFilter(const SkRect& srcRect,
                           SkScalar inset,
                           sk_sp<SkImageFilter> input,
                           const CropRect* cropRect);
    void flatten(SkWriteBuffer&) const override;

    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
                                        SkIPoint* offset) const override;
    sk_sp<SkImageFilter> onMakeColorSpace(SkColorSpaceXformer*) const override;

private:
    static sk_sp<SkFlattenable> CreateProc(SkReadBuffer&);
    friend class SkFlattenable::PrivateInitializer;

    SkRect   fSrcRect;
    SkScalar fInset;

    typedef SkImageFilter INHERITED;
};

#endif

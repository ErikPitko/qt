/*
    Copyright (C) 2004, 2005, 2006, 2007 Nikolas Zimmermann <zimmermann@kde.org>
                  2004, 2005 Rob Buis <buis@kde.org>
                  2005 Eric Seidel <eric@webkit.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    aint with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef SVGFEComponentTransfer_h
#define SVGFEComponentTransfer_h

#if ENABLE(FILTERS)
#include "FilterEffect.h"

#include "SVGFEDisplacementMap.h"
#include "Filter.h"
#include <wtf/Vector.h>

namespace WebCore {

    enum ComponentTransferType {
        FECOMPONENTTRANSFER_TYPE_UNKNOWN  = 0,
        FECOMPONENTTRANSFER_TYPE_IDENTITY = 1,
        FECOMPONENTTRANSFER_TYPE_TABLE    = 2,
        FECOMPONENTTRANSFER_TYPE_DISCRETE = 3,
        FECOMPONENTTRANSFER_TYPE_LINEAR   = 4,
        FECOMPONENTTRANSFER_TYPE_GAMMA    = 5
    };

    struct ComponentTransferFunction {
        ComponentTransferFunction()
            : type(FECOMPONENTTRANSFER_TYPE_UNKNOWN)
            , slope(0.0f)
            , intercept(0.0f)
            , amplitude(0.0f)
            , exponent(0.0f)
            , offset(0.0f)
        {
        }

        ComponentTransferType type;

        float slope;
        float intercept;
        float amplitude;
        float exponent;
        float offset;

        Vector<float> tableValues;
    };

    class FEComponentTransfer : public FilterEffect {
    public:
        static PassRefPtr<FEComponentTransfer> create(FilterEffect*, const ComponentTransferFunction&, 
                const ComponentTransferFunction&, const ComponentTransferFunction&, const ComponentTransferFunction&);

        ComponentTransferFunction redFunction() const;
        void setRedFunction(const ComponentTransferFunction&);

        ComponentTransferFunction greenFunction() const;
        void setGreenFunction(const ComponentTransferFunction&);

        ComponentTransferFunction blueFunction() const;
        void setBlueFunction(const ComponentTransferFunction&);

        ComponentTransferFunction alphaFunction() const;
        void setAlphaFunction(const ComponentTransferFunction&);

        virtual FloatRect uniteChildEffectSubregions(Filter* filter) { return calculateUnionOfChildEffectSubregions(filter, m_in.get()); }
        void apply(Filter*);
        void dump();

    private:
        FEComponentTransfer(FilterEffect*,const ComponentTransferFunction&, const ComponentTransferFunction&,
                const ComponentTransferFunction&, const ComponentTransferFunction&);

        RefPtr<FilterEffect> m_in;
        ComponentTransferFunction m_redFunc;
        ComponentTransferFunction m_greenFunc;
        ComponentTransferFunction m_blueFunc;
        ComponentTransferFunction m_alphaFunc;
    };

} // namespace WebCore

#endif // ENABLE(FILTERS)

#endif // SVGFEComponentTransfer_h

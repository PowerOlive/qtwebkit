/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CCRenderPassDrawQuad_h
#define CCRenderPassDrawQuad_h

#include <public/WebCompositorQuad.h>
#include <public/WebFilterOperations.h>
#include <public/WebTransformationMatrix.h>
#include <wtf/PassOwnPtr.h>

namespace WebCore {

class CCRenderPass;

class CCRenderPassDrawQuad : public WebKit::WebCompositorQuad {
    WTF_MAKE_NONCOPYABLE(CCRenderPassDrawQuad);
public:
    static PassOwnPtr<CCRenderPassDrawQuad> create(const WebKit::WebCompositorSharedQuadState*, const IntRect&, int renderPassId, bool isReplica, const WebKit::WebTransformationMatrix&, const WebKit::WebFilterOperations& filters, const WebKit::WebFilterOperations& backgroundFilters, unsigned maskTextureId, const IntRect& contentsChangedSinceLastFrame);

    int renderPassId() const { return m_renderPassId; }
    bool isReplica() const { return m_isReplica; }
    unsigned maskTextureId() const { return m_maskTextureId; }
    const IntRect& contentsChangedSinceLastFrame() const { return m_contentsChangedSinceLastFrame; }

    // FIXME: This should be removed and we should draw the RenderPass with the quadTransform.
    const WebKit::WebTransformationMatrix& drawTransform() const { return m_drawTransform; }

    const WebKit::WebFilterOperations& filters() const { return m_filters; }
    const WebKit::WebFilterOperations& backgroundFilters() const { return m_backgroundFilters; }

    static const CCRenderPassDrawQuad* materialCast(const WebKit::WebCompositorQuad*);
private:
    CCRenderPassDrawQuad(const WebKit::WebCompositorSharedQuadState*, const IntRect&, int renderPassId, bool isReplica, const WebKit::WebTransformationMatrix&, const WebKit::WebFilterOperations& filters, const WebKit::WebFilterOperations& backgroundFilters, unsigned maskTextureId, const IntRect& contentsChangedSinceLastFrame);

    int m_renderPassId;
    bool m_isReplica;
    WebKit::WebTransformationMatrix m_drawTransform;
    WebKit::WebFilterOperations m_filters;
    WebKit::WebFilterOperations m_backgroundFilters;
    unsigned m_maskTextureId;
    IntRect m_contentsChangedSinceLastFrame;
};

}

#endif
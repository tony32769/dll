//=======================================================================
// Copyright (c) 2014-2017 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#pragma once

//Forward declaration of the layers

namespace dll {

template <typename Desc>
struct rbm;

template <typename Desc>
struct dyn_rbm;

template <typename Desc>
struct conv_rbm;

template <typename Desc>
struct dyn_conv_rbm;

template <typename Desc>
struct conv_rbm_mp;

template <typename Desc>
struct dyn_conv_rbm_mp;

template <typename Desc>
struct mp_layer_3d;

template <typename Desc>
struct dyn_mp_layer_3d;

template <typename Desc>
struct avgp_layer_3d;

template <typename Desc>
struct dyn_avgp_layer_3d;

template <typename Desc>
struct upsample_layer_3d;

template <typename Desc>
struct dyn_upsample_layer_3d;

template <typename Desc>
struct binarize_layer;

template <typename Desc>
struct normalize_layer;

template <typename Desc>
struct rectifier_layer;

template <typename Desc>
struct random_layer;

template <typename Desc>
struct lcn_layer;

template <typename Desc>
struct dyn_lcn_layer;

template <typename Desc>
struct scale_layer;

template <typename Desc>
struct dense_layer;

template <typename Desc>
struct dyn_dense_layer;

template <typename Desc>
struct conv_layer;

template <typename Desc>
struct dyn_conv_layer;

template <typename Desc>
struct deconv_layer;

template <typename Desc>
struct dyn_deconv_layer;

template <typename Desc>
struct activation_layer;

} //end of dll namespace

//=======================================================================
// Copyright (c) 2014-2017 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#pragma once

namespace dll {

/*!
 * \brief A descriptor for a 2D Batch Normalization layer.
 */
template<size_t I, typename... Parameters>
struct batch_normalization_layer_2d_desc {
    /*!
     * \brief Input Size
     */
    static constexpr size_t Input  = I;

    /*!
     * The type used to store the weights
     */
    using weight = typename detail::get_type<weight_type<float>, Parameters...>::value;

    /*!
     * The layer type
     */
    using layer_t = batch_normalization_2d_layer<batch_normalization_layer_2d_desc<Input, Parameters...>>;

    /*!
     * The dynamic layer type
     */
    using dyn_layer_t = dyn_batch_normalization_2d_layer<batch_normalization_layer_2d_desc<Input, Parameters...>>;

    //Make sure only valid types are passed to the configuration list
    static_assert(
        detail::is_valid<cpp::type_list<weight_type_id>, Parameters...>::value,
        "Invalid parameters type for batch_normalization_2d_desc");
};

/*!
 * \brief A descriptor for a dynamic 2D Batch Normalization layer.
 */
template<typename... Parameters>
struct dyn_batch_normalization_layer_2d_desc {
    /*!
     * The type used to store the weights
     */
    using weight = typename detail::get_type<weight_type<float>, Parameters...>::value;

    /*!
     * The layer type
     */
    using layer_t = dyn_batch_normalization_2d_layer<dyn_batch_normalization_layer_2d_desc<Parameters...>>;

    /*!
     * The dynamic layer type
     */
    using dyn_layer_t = dyn_batch_normalization_2d_layer<dyn_batch_normalization_layer_2d_desc<Parameters...>>;

    //Make sure only valid types are passed to the configuration list
    static_assert(
        detail::is_valid<cpp::type_list<weight_type_id>, Parameters...>::value,
        "Invalid parameters type for batch_normalization_2d_desc");
};

/*!
 * \brief A descriptor for a 4D Batch Normalization layer.
 */
template<size_t K, size_t W, size_t H, typename... Parameters>
struct batch_normalization_layer_4d_desc {
    /*!
     * \brief Number of feature maps
     */
    static constexpr size_t Kernels = K;

    /*!
     * \brief Width of a feature map
     */
    static constexpr size_t Width = W;

    /*!
     * \brief Height of a feature map
     */
    static constexpr size_t Height = H;

    /*!
     * The type used to store the weights
     */
    using weight = typename detail::get_type<weight_type<float>, Parameters...>::value;

    /*!
     * The layer type
     */
    using layer_t = batch_normalization_4d_layer<batch_normalization_layer_4d_desc<K, W, H, Parameters...>>;

    /*!
     * The dynamic layer type
     */
    using dyn_layer_t = dyn_batch_normalization_4d_layer<batch_normalization_layer_4d_desc<K, W, H, Parameters...>>;

    //Make sure only valid types are passed to the configuration list
    static_assert(
        detail::is_valid<cpp::type_list<weight_type_id>, Parameters...>::value,
        "Invalid parameters type for batch_normalization_4d_desc");
};

/*!
 * \brief A descriptor for a dynamic 4D Batch Normalization layer.
 */
template<typename... Parameters>
struct dyn_batch_normalization_layer_4d_desc {
    /*!
     * The type used to store the weights
     */
    using weight = typename detail::get_type<weight_type<float>, Parameters...>::value;

    /*!
     * The layer type
     */
    using layer_t = dyn_batch_normalization_4d_layer<dyn_batch_normalization_layer_4d_desc<Parameters...>>;

    /*!
     * The dynamic layer type
     */
    using dyn_layer_t = dyn_batch_normalization_4d_layer<dyn_batch_normalization_layer_4d_desc<Parameters...>>;

    //Make sure only valid types are passed to the configuration list
    static_assert(
        detail::is_valid<cpp::type_list<weight_type_id>, Parameters...>::value,
        "Invalid parameters type for batch_normalization_4d_desc");
};

} //end of dll namespace

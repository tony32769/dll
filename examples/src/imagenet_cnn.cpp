//=======================================================================
// Copyright (c) 2014-2017 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include "dll/neural/conv_layer.hpp"
#include "dll/neural/dense_layer.hpp"
#include "dll/neural/conv_same_layer.hpp"
#include "dll/pooling/mp_layer.hpp"
#include "dll/network.hpp"

#include "dll/datasets.hpp"
#include "dll/datasets/imagenet.hpp"

#include "mnist/mnist_reader.hpp"
#include "mnist/mnist_utils.hpp"

int main(int /*argc*/, char* /*argv*/ []) {
    constexpr size_t B = 64;

    // Load the dataset
    auto dataset = dll::make_imagenet_dataset("/home/wichtounet/datasets/imagenet_resized/", 0
        , dll::batch_size<B>{}
        , dll::scale_pre<255>{}
        , dll::big_batch_size<1>{}
        dll::threaded{}
        );

    // Build the network

    using network_t = dll::dyn_network_desc<
        dll::dbn_layers<
            dll::conv_same_desc<3, 256, 256, 16, 3, 3, dll::activation<dll::function::RELU>>::layer_t,
            dll::mp_layer_3d_desc<16, 256, 256, 1, 2, 2>::layer_t,

            dll::conv_same_desc<16, 128, 128, 16, 3, 3, dll::activation<dll::function::RELU>>::layer_t,
            dll::mp_layer_3d_desc<16, 128, 128, 1, 2, 2>::layer_t,

            dll::conv_same_desc<16, 64, 64, 32, 3, 3, dll::activation<dll::function::RELU>>::layer_t,
            dll::mp_layer_3d_desc<32, 64, 64, 1, 2, 2>::layer_t,

            dll::conv_same_desc<32, 32, 32, 32, 3, 3, dll::activation<dll::function::RELU>>::layer_t,
            dll::mp_layer_3d_desc<32, 32, 32, 1, 2, 2>::layer_t,

            dll::conv_same_desc<32, 16, 16, 32, 3, 3, dll::activation<dll::function::RELU>>::layer_t,
            dll::mp_layer_3d_desc<32, 16, 16, 1, 2, 2>::layer_t,

            dll::dense_desc<2048, 2048, dll::activation<dll::function::RELU>>::layer_t,
            dll::dense_desc<2048, 1000, dll::activation<dll::function::SOFTMAX>>::layer_t
        >,
        dll::batch_size<B>,
        dll::updater<dll::updater_type::MOMENTUM>,
        dll::verbose,
        dll::no_epoch_error>::dbn_t;

    auto net = std::make_unique<network_t>();

    // Display the network and dataset
    net->display();
    dataset.display();

    // Train the network
    net->fine_tune(dataset.train(), 25);

    // Test the network on test set
    net->evaluate(dataset.test());

    return 0;
}

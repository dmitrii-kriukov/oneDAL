/* file: spatial_pooling2d_layer_backward_kernel.h */
/*******************************************************************************
* Copyright 2014-2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

//++
//  Declaration of template function that calculate backward pooling layer relults.
//--

#ifndef __SPATIAL_POOLING2D_LAYER_BACKWARD_KERNEL_H__
#define __SPATIAL_POOLING2D_LAYER_BACKWARD_KERNEL_H__

#include "algorithms/neural_networks/layers/spatial_pooling2d/spatial_pooling2d_layer_backward_types.h"
#include "algorithms/kernel/neural_networks/layers/spatial_pooling2d_layer/spatial_pooling2d_layer_internal_types.h"
#include "algorithms/kernel/kernel.h"
#include "data_management/data/tensor.h"
#include "algorithms/neural_networks/layers/pooling2d/maximum_pooling2d_layer_backward.h"
#include "algorithms/neural_networks/layers/spatial_pooling2d/spatial_stochastic_pooling2d_layer.h"
#include "algorithms/neural_networks/layers/spatial_pooling2d/spatial_maximum_pooling2d_layer.h"
#include "algorithms/neural_networks/layers/spatial_pooling2d/spatial_average_pooling2d_layer.h"

using namespace daal::data_management;
using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace spatial_pooling2d
{
namespace backward
{
namespace internal
{
using namespace spatial_pooling2d::internal;

/**
 *  \brief Kernel for forward pooling layer results computation
 */
template <typename algorithmFPType, Method method, CpuType cpu>
class DAAL_EXPORT PoolingKernel : public Kernel
{};

template <typename algorithmFPType, CpuType cpu>
class DAAL_EXPORT PoolingKernel<algorithmFPType, maximum, cpu> : public Kernel
{
public:
    virtual services::Status compute(const Tensor & inputGradientTensor, Tensor & gradientTensor, const Tensor & selectedPosTensor,
                                     const spatial_maximum_pooling2d::Parameter & parameter);
};

template <typename algorithmFPType, CpuType cpu>
class DAAL_EXPORT PoolingKernel<algorithmFPType, stochastic, cpu> : public Kernel
{
public:
    virtual services::Status compute(const Tensor & inputGradientTensor, Tensor & gradientTensor, const Tensor & selectedPosTensor,
                                     const spatial_stochastic_pooling2d::Parameter & parameter);
};

template <typename algorithmFPType, CpuType cpu>
class DAAL_EXPORT PoolingKernel<algorithmFPType, average, cpu> : public Kernel
{
public:
    virtual services::Status compute(const Tensor & inputGradientTensor, Tensor & gradientTensor,
                                     const spatial_average_pooling2d::Parameter & parameter);
};

} // namespace internal
} // namespace backward
} // namespace spatial_pooling2d
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal

#endif

/* file: spatial_pooling2d_layer_forward_kernel.h */
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
//  Declaration of template function that calculate forward pooling layer relults.
//--

#ifndef __SPATIAL_POOLING2D_LAYER_FORWARD_KERNEL_H__
#define __SPATIAL_POOLING2D_LAYER_FORWARD_KERNEL_H__

#include "algorithms/neural_networks/layers/spatial_pooling2d/spatial_pooling2d_layer_forward_types.h"
#include "algorithms/kernel/neural_networks/layers/spatial_pooling2d_layer/spatial_pooling2d_layer_internal_types.h"
#include "algorithms/kernel/kernel.h"
#include "data_management/data/tensor.h"

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
namespace forward
{
namespace internal
{
/**
 *  \brief Kernel for forward pooling layer results computation
 */
template <typename algorithmFPType, CpuType cpu>
class BasePoolingKernel : public Kernel
{
public:
    virtual services::Status compute(const Tensor & dataTensor, Tensor & valueTensor, Tensor * selectedPosTensor,
                                     const spatial_pooling2d::Parameter & parameter);

protected:
    virtual Status computePooling(const pooling2d::Parameter & poolingPar, const spatial_pooling2d::Parameter & spatialParameter,
                                  const Tensor & dataTensor, Tensor & valueTensor, Tensor * selectedPosTensor) = 0;
};

/**
 *  \brief Kernel for forward pooling layer results computation
 */
template <typename algorithmFPType, spatial_pooling2d::internal::Method method, CpuType cpu>
class PoolingKernel : public BasePoolingKernel<algorithmFPType, cpu>
{
protected:
    Status computePooling(const pooling2d::Parameter & poolingPar, const spatial_pooling2d::Parameter & spatialParameter, const Tensor & dataTensor,
                          Tensor & valueTensor, Tensor * selectedPosTensor);
};

template <typename algorithmFPType, CpuType cpu>
class PoolingKernel<algorithmFPType, spatial_pooling2d::internal::maximum, cpu> : public BasePoolingKernel<algorithmFPType, cpu>
{
protected:
    Status computePooling(const pooling2d::Parameter & poolingPar, const spatial_pooling2d::Parameter & spatialParameter, const Tensor & dataTensor,
                          Tensor & valueTensor, Tensor * selectedPosTensor);
};

template <typename algorithmFPType, CpuType cpu>
class PoolingKernel<algorithmFPType, spatial_pooling2d::internal::stochastic, cpu> : public BasePoolingKernel<algorithmFPType, cpu>
{
protected:
    Status computePooling(const pooling2d::Parameter & poolingPar, const spatial_pooling2d::Parameter & spatialParameter, const Tensor & dataTensor,
                          Tensor & valueTensor, Tensor * selectedPosTensor);
};

template <typename algorithmFPType, CpuType cpu>
class PoolingKernel<algorithmFPType, spatial_pooling2d::internal::average, cpu> : public BasePoolingKernel<algorithmFPType, cpu>
{
private:
    Status computePooling(const pooling2d::Parameter & poolingPar, const spatial_pooling2d::Parameter & spatialParameter, const Tensor & dataTensor,
                          Tensor & valueTensor, Tensor * selectedPosTensor);
};
} // namespace internal
} // namespace forward
} // namespace spatial_pooling2d
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal

#endif

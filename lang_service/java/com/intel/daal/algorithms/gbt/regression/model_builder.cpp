/* file: model_builder.cpp */
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

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>

#include "daal.h"
#include "com_intel_daal_algorithms_gbt_regression_ModelBuilder.h"
#include "lang_service/java/com/intel/daal/include/common_helpers_functions.h"

using namespace daal;
using namespace daal::algorithms::gbt::regression;
using namespace daal::data_management;
using namespace daal::services;

/*
* Class:     com_intel_daal_algorithms_gbt_regression_ModelBuilder
* Method:    cInit
* Signature: (JIII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_regression_ModelBuilder_cInit(JNIEnv * env, jobject, jlong nFeatures, jlong nIterations)
{
    jlong modelBuilderAddr = (jlong)(new SharedPtr<ModelBuilder>(new ModelBuilder(nFeatures, nIterations)));

    services::SharedPtr<ModelBuilder> * ptr = new services::SharedPtr<ModelBuilder>();
    *ptr                                    = staticPointerCast<ModelBuilder>(*(SharedPtr<ModelBuilder> *)modelBuilderAddr);
    DAAL_CHECK_THROW((*ptr)->getStatus());

    return modelBuilderAddr;
}

/*
* Class:     com_intel_daal_algorithms_gbt_regression_ModelBuilder
* Method:    cCreateTree
* Signature: (JIII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_regression_ModelBuilder_cCreateTree(JNIEnv * env, jobject, jlong algAddr, jlong nNodes)
{
    services::SharedPtr<ModelBuilder> * ptr = new services::SharedPtr<ModelBuilder>();
    *ptr                                    = staticPointerCast<ModelBuilder>(*(SharedPtr<ModelBuilder> *)algAddr);
    long treeId                             = (*ptr)->createTree(nNodes);
    DAAL_CHECK_THROW((*ptr)->getStatus());
    return treeId;
}

/*
* Class:     com_intel_daal_algorithms_gbt_regression_ModelBuilder
* Method:    cAddSplitNode
* Signature: (JIII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_regression_ModelBuilder_cAddSplitNode(JNIEnv * env, jobject, jlong algAddr, jlong treeId,
                                                                                                 jlong parentId, jlong position, jlong featureIndex,
                                                                                                 jdouble featureValue)
{
    services::SharedPtr<ModelBuilder> * ptr = new services::SharedPtr<ModelBuilder>();
    *ptr                                    = staticPointerCast<ModelBuilder>(*(SharedPtr<ModelBuilder> *)algAddr);
    long nodeId                             = (*ptr)->addSplitNode(treeId, parentId, position, featureIndex, static_cast<double>(featureValue));
    DAAL_CHECK_THROW((*ptr)->getStatus());
    return nodeId;
}

/*
* Class:     com_intel_daal_algorithms_gbt_regression_ModelBuilder
* Method:    cAddLeafNode
* Signature: (JIII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_regression_ModelBuilder_cAddLeafNode(JNIEnv * env, jobject, jlong algAddr, jlong treeId,
                                                                                                jlong parentId, jlong position, jdouble response)
{
    services::SharedPtr<ModelBuilder> * ptr = new services::SharedPtr<ModelBuilder>();
    *ptr                                    = staticPointerCast<ModelBuilder>(*(SharedPtr<ModelBuilder> *)algAddr);
    long nodeId                             = (*ptr)->addLeafNode(treeId, parentId, position, response);
    DAAL_CHECK_THROW((*ptr)->getStatus());
    return nodeId;
}

/*
 * Class:     com_intel_daal_algorithms_gbt_regression_ModelBuilder
 * Method:    cGetModel
 * Signature:(JII)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_gbt_regression_ModelBuilder_cGetModel(JNIEnv * env, jobject thisObj, jlong algAddr)
{
    services::SharedPtr<ModelBuilder> * ptr = new services::SharedPtr<ModelBuilder>();
    *ptr                                    = staticPointerCast<ModelBuilder>(*(SharedPtr<ModelBuilder> *)algAddr);
    ModelPtr * model                        = new ModelPtr;
    *model                                  = staticPointerCast<Model>((*ptr)->getModel());
    return (jlong)model;
}

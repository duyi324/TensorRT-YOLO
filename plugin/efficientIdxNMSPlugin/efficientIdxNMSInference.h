/*
 * SPDX-FileCopyrightText: Copyright (c) 1993-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TRT_EFFICIENT_IDX_NMS_INFERENCE_H
#define TRT_EFFICIENT_IDX_NMS_INFERENCE_H

#include "common/plugin.h"

#include "efficientIdxNMSParameters.h"

size_t EfficientIdxNMSWorkspaceSize(
    int32_t batchSize, int32_t numScoreElements, int32_t numClasses, nvinfer1::DataType datatype);

pluginStatus_t EfficientIdxNMSInference(nvinfer1::plugin::EfficientIdxNMSParameters param, void const* boxesInput,
    void const* scoresInput, void const* anchorsInput, void* numDetectionsOutput, void* nmsBoxesOutput,
    void* nmsScoresOutput, void* nmsClassesOutput, void* nmsIndicesOutput, void* workspace, cudaStream_t stream);

#endif

/*
 * Copyright 2017-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ALEXA_CLIENT_SDK_AVSCOMMON_UTILS_INCLUDE_AVSCOMMON_UTILS_FUNCTIONAL_HASH_H_
#define ALEXA_CLIENT_SDK_AVSCOMMON_UTILS_INCLUDE_AVSCOMMON_UTILS_FUNCTIONAL_HASH_H_

#include <climits>
#include <functional>

namespace alexaClientSDK {
namespace avsCommon {
namespace utils {
namespace functional {

/**
 * Function to combine hash values in to a single hash value.
 * Combination by XOR. A circular rotate left is applied to the seed value before the XOR so that combining hashes
 * generated by the same hash function for the same value (a common use case) won't degenerate to zero.
 *
 * @param seed Accumulated value from multiple calls.
 * @param value The next value whose hash is to be combined.
 */
template <typename Type>
void hashCombine(size_t& seed, Type const& value) {
    constexpr int bitsMinus1 = (CHAR_BIT * sizeof(size_t)) - 1;
    std::hash<Type> hasher;
    seed = hasher(value) ^ ((seed << 1) | ((seed >> bitsMinus1) & 1));
}

}  // namespace functional
}  // namespace utils
}  // namespace avsCommon
}  // namespace alexaClientSDK

#endif  // ALEXA_CLIENT_SDK_AVSCOMMON_UTILS_INCLUDE_AVSCOMMON_UTILS_FUNCTIONAL_HASH_H_

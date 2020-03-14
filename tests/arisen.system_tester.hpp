/**
 *  @file
 *  @copyright defined in rsn/LICENSE.txt
 */
#pragma once

#include "contracts.hpp"
#include <arisen/chain/abi_serializer.hpp>
#include <arisen/testing/tester.hpp>

#include <fc/variant_object.hpp>
#include <fstream>

using namespace arisen::chain;
using namespace arisen::testing;
using namespace fc;

using mvo = fc::mutable_variant_object;

#ifndef TESTER
#ifdef NON_VALIDATING_TEST
#define TESTER tester
#else
#define TESTER validating_tester
#endif
#endif

extern bool write_mode;

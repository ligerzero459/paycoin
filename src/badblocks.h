// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2015 The Peercoin developers
// Copyright (c) 2014-2015 The Paycoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef PAYCOIN_BADBLOCK_H
#define  PAYCOIN_BADBLOCK_H

#include <map>
#include "net.h"
#include "util.h"

class uint256;

/** Block-chain checkpoints are compiled-in sanity checks.
 * They are updated every release or three.
 */
namespace Badblocks
{
    // Returns true if block passes checkpoint checks
    bool CheckBadList(int nHeight, const uint256& hash);
}

#endif

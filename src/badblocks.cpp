// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2015 The Peercoin developers
// Copyright (c) 2014-2015 The Paycoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "badblocks.h"

#include "db.h"
#include "main.h"
#include "uint256.h"

namespace Badblocks
{
    typedef std::map<int, uint256> MapBadblocks;   // fork blocks

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapBadblocks mapBadblocks =
        boost::assign::map_list_of
        ( 328799, uint256("0xa9dd866b2b34ef7c4dae2c873968c046bb091f878a44045055a38ed4fe0db259"))
        ;

    static MapBadblocks mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 0, uint256("0x0000000000000000000000000000000000000000000000000000000000000000"))
        ;

    bool CheckBadList(int nHeight, const uint256& hash)
    {
        MapBadblocks& badblocks = (fTestNet ? mapCheckpointsTestnet : mapBadblocks);

        MapBadblocks::const_iterator i = badblocks.find(nHeight);
        if (i == badblocks.end()) return false;
        return hash == i->second;
    } 
}

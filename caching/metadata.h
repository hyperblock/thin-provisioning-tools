#ifndef CACHE_METADATA_H
#define CACHE_METADATA_H

#include "persistent-data/block.h"
#include "persistent-data/data-structures/array.h"
#include "persistent-data/endian_utils.h"
#include "persistent-data/space-maps/disk.h"
#include "persistent-data/transaction_manager.h"

#include "caching/superblock.h"
#include "caching/hint_array.h"
#include "caching/mapping_array.h"

//----------------------------------------------------------------

namespace caching {
	class metadata {
	public:
		enum open_type {
			CREATE,
			OPEN
		};

		typedef block_manager<>::read_ref read_ref;
		typedef block_manager<>::write_ref write_ref;
		typedef boost::shared_ptr<metadata> ptr;

		metadata(block_manager<>::ptr bm, open_type ot);

		void commit();

		typedef persistent_data::transaction_manager tm;
		tm::ptr tm_;
		superblock_detail::superblock sb_;
		checked_space_map::ptr metadata_sm_;
		mapping_array::ptr mappings_;
		//hint_array::ptr hints_;
	};
};

//----------------------------------------------------------------

#endif
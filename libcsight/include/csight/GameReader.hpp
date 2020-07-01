#pragma once

#include "../../../Atmosphere-libs/libstratosphere/source/dmnt/dmntcht.h"
#include <csight/PK8.hpp>
#include <csight/RaidDetails.hpp>
#include <switch.h>
#include <vector>

namespace csight {
  class GameReader : public raid::RaidDetails {
   public:
    GameReader(bool shouldUseSmallMemoryMode);
    Result attach();
    bool getIsPokemonRunning();
    bool getIsServiceRunning();
    std::vector<std::shared_ptr<PK8>> readParty();
    std::vector<std::shared_ptr<PK8>> readBoxes();
    std::shared_ptr<PK8> readWild();
    std::shared_ptr<PK8> readRaid();
    std::shared_ptr<PK8> readTrade();
    u64 getTitleId() override;

   private:
    bool m_isDebugServiceRunning = false;
    u64 m_partyOffset = 0x450BE8C0;
    u64 m_boxOffset = 0x4506D890;
    u64 m_wildOffset = 0x8FEA3358;
    u64 m_raidOffset = 0x886C1BD8;
    u64 m_legendOffset = 0x886BC058;
    u64 m_tradeOffset = 0xAF285F68;
    DmntCheatProcessMetadata m_metadata;

    Result readHeap(u64 address, void *buffer, size_t size) override;
    std::shared_ptr<PK8> readPK8(u64 offset);
    std::vector<std::shared_ptr<PK8>> readPK8s(u64 offset, u32 amount, u32 bytesBetweenPokemon);
  };
}  // namespace csight

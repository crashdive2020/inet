//
// Copyright (C) OpenSim Ltd.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef __INET_GranularityClock_H
#define __INET_GranularityClock_H

#include "inet/common/clock/base/PredictableClockBase.h"

namespace inet {

/**
 * Models a clock with a constant granularity.
 */
class INET_API GranularityClock : public PredictableClockBase
{
  protected:
    struct TimePair {
        simtime_t simtime;
        clocktime_t clocktime;
    };
    TimePair origin;
    clocktime_t granularity;
    int64_t granularityRaw;    // cached granularity.raw()
    double driftRate;

  public:
    virtual void initialize() override;

    virtual clocktime_t granularize(clocktime_t clock) const;
    virtual clocktime_t granularizeUp(clocktime_t clock) const;
    virtual clocktime_t fromSimTimePrecise(simtime_t t) const;
    virtual clocktime_t fromSimTime(simtime_t t) const override;
    virtual simtime_t toSimTime(clocktime_t t) const override;

    virtual void scheduleClockEventAt(clocktime_t t, ClockEvent *msg) override;
    virtual void scheduleClockEventAfter(clocktime_t t, ClockEvent *msg) override;
};

} // namespace inet

#endif // ifndef __INET_GranularityClock_H


//
// Copyright (C) 2015 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see http://www.gnu.org/licenses/.
//
// Author: Andras Varga
//

package inet.linklayer.common;

//
// An example QoS classifier that assigns a User Priority based on
// the transport protocol and port numbers.
//
simple ExampleQosClassifier like IIeee8021dQosClassifier
{
    parameters:
        @display("i=block/classifier");
    gates:
        input in;
        output out;
}


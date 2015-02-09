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

#ifndef RESALLOCATOR_H_
#define RESALLOCATOR_H_

#include <Allocate.h>

#define ACCEPTED 0
#define REJECTED 1 //this goes out to .rest because there's no gate[1]

class ResAllocator: public queueing::Allocate {
    private:
        queueing::IResourcePool *resourcePool;
        int resourceAmount;
        int resourcePriority;

        // statistics
        simsignal_t droppedSignal;
        simsignal_t queueLengthSignal;
        simsignal_t queueingTimeSignal;
    public:
        ResAllocator();
        virtual ~ResAllocator();
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual bool allocateResource(queueing::Job *job);
};

#endif /* RESALLOCATOR_H_ */

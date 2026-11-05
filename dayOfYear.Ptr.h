#include "dayOfYear.h"

namespace kwonyonje2649061
{
    class dayOfYearPtr
    {
        dayOfYear* dPtr;
    public: 
        dayOfYearPtr(const dayOfYear& d = dayOfYear{1,1}) : dPtr{new dayOfYear{d}} {}
        ~dayOfYearPtr(){ delete dPtr; }
        dayOfYearPtr(const dayOfYearPtr& copy)
        {
            dptr = copy.dPtr ? new dayOfYear{ *copy.dPtr } : nullptr ;
        }
        dayOfYearPtr(dayOfYearPtr&& move) noexcept
        {
            std::cout<< "move constructor\n";
            dPtr = move.dPtr;
            move.dPtr = nullptr;
        }
        dayOfYearPtr& operator=(const dayOfYearPtr& copy)
        {
            if ( this != &copy)
            {
                delete dPtr;
                dptr = copy.dPtr ? new dayOfYear{ *copy.dPtr } : nullptr ;
            }
            return *this;
        }
        dayOfYearPtr& operator=(dayOfYearPtr&& move) noexcept
        {
            std::cout<< "move operator\n";
            if (this != &move)
            {
                delete dPtr;
                dPtr = move.dPtr;
                move.dPtr = nullptr;
            }
            return *this;
        }
        void print() const
        {
            if (dPtr) std::cout<< *dPtr;
            else std::cout<< "no daya\n";;
        }
    };
}
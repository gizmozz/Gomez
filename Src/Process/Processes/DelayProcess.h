#ifndef DELAYPROCESS_H
#define DELAYPROCESS_H

#include "../Process.h"

class DelayProcess : public Process
{
private:

	unsigned long m_timeToDelay;
	unsigned long m_timeDelayed;
	
public:

	DelayProcess(unsigned long timeToDelay);
	~DelayProcess();

protected:

	virtual void VUpdate(unsigned int elapsedTime);
};

#endif

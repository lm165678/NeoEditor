#ifndef NEO_NPKPUBLISHER_H
#define NEO_NPKPUBLISHER_H

#include <NeoEngine.h>
#include "Publisher.h"

namespace Publish
{

class NPKPublisher : public Publisher
{
	bool packageDir(const char* dir, const char* pwd, Neo::PackageManager* pkm, Neo::Package pkg, bool verbose = false);
public:

	virtual const char* getName() override
	{
		return "NPK";
	}

	virtual bool publish(const char* projectFile,
						 const char* executable,
						 const char* output,
						 bool verbose = false,
						 const char* levelOverride = nullptr,
						 std::function<void(int)> progressCallback = nullptr) override;
};

}

#endif //NEO_NPKPUBLISHER_H

#include <impl/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>

using rapidjson::Document;
using rapidjson::Value;

namespace jcbm {
	RapidJson::RapidJson() {
	}

	RapidJson::~RapidJson() {
	}

	bool RapidJson::doesDomKeepOrder(const std::string& q, const std::list<std::string>& a) const {
		// step 1. parse a JSON string into DOM
		Document d;
		d.Parse(q.c_str());
		
		// step 2. access sequentially
		if (d.IsObject()) {
			Value::ConstMemberIterator qIter = d.MemberBegin();
			std::list<std::string>::const_iterator aIter = a.begin();
			while (qIter != d.MemberEnd()) {
				std::cout << "parsing result: " << qIter->name.GetString() << ", expected result: " << (*aIter) << std::endl;

				// step 2.1. check result
				if (qIter->name.GetString() != (*aIter)) {
					return false;
				}
				
				// step 2.2. do next
				qIter++;
				aIter++;
			}
		}

		return true;
	}

	bool RapidJson::doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const {
		return true;
	}
}

#ifndef __PROTON_RT_PARSER_HH__
#define __PROTON_RT_PARSER_HH__
#include <string>
#include <sstream>
#include <cstdint>
#include <unordered_map>
namespace KHPS
{
	//TODO:	
	struct rt_parser {
	public:
		bool parsing(const std::string& str) noexcept;
		bool contain(const std::string& str) noexcept;

		const std::string get(const std::string& key) noexcept;
		const std::unordered_map<std::string, std::string> data();
		
		const bool try_get(const std::string& key, std::string& value);
		const bool try_get(const std::string& key, int& value);
		const bool try_get(const std::string& key, unsigned int& value);
		const bool try_get(const std::string& key, float& value);
		const bool try_get(const std::string& key, double& value);
		const bool try_get(const std::string& key, bool& value);
		const bool try_get(const std::string& key, const char* value);
	private:
		std::unordered_map<std::string, std::string> m_data = {};
	};
}
#endif // !__PROTON_RT_PARSER_HH__

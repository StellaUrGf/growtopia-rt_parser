#include <proton/rt_parser.hh>
#include <iostream>
namespace KHPS
{
	bool rt_parser::parsing(const std::string& str) noexcept
	{
		if (str.empty())
			return false;
		try {
			_STD istringstream iss(str);
			std::string line;
			while (_STD getline(iss, line)) {
				if (line.find('|') != std::string::npos) {
					uint16_t pos = (uint16_t)line.find('|');
					::std::string key = line.substr(0x0, pos);
					::std::string val = line.substr(pos + 1);
					if (!(key.empty() && val.empty())) {
						m_data[key] = val;
					}
				}
			}
		} catch (std::exception err) {
			return false;
		}
		return true;
	}
	bool rt_parser::contain(const std::string& str) noexcept
	{
		if (auto pair = m_data.find(str); pair != m_data.end())
			return true;
		return false;
	}
	const std::string rt_parser::get(const std::string& key) noexcept
	{
		if (auto pair = m_data.find(key); pair != m_data.end())
			return pair->second;
		return std::string("");
	}
	const std::unordered_map<std::string, std::string> rt_parser::data()
	{
		return m_data;
	}
	const bool rt_parser::try_get(const std::string& key, std::string& value)
	{
		if (auto pair = m_data.find(key); pair != m_data.end()) {
			value = pair->second;
			return true;
		}
		return false;
	}
	const bool rt_parser::try_get(const std::string& key, int& value)
	{
		if (auto pair = m_data.find(key); pair != m_data.end()) {
			value = _STD atoi(pair->second.c_str());
			return true;
		}
		return false;
	}
	const bool rt_parser::try_get(const std::string& key, unsigned int& value)
	{
		if (auto pair = m_data.find(key); pair != m_data.end()) {
			value = ((uint32_t)_STD atoi(pair->second.c_str()));
			return true;
		}
		return false;
	}
	const bool rt_parser::try_get(const std::string& key, float& value)
	{
		if (auto pair = m_data.find(key); pair != m_data.end()) {
			value = ((float)_STD atof(pair->second.c_str()));
			return true;
		}
		return false;
	}
	const bool rt_parser::try_get(const std::string& key, double& value)
	{
		if (auto pair = m_data.find(key); pair != m_data.end()) {
			value = ((double)_STD atof(pair->second.c_str()));
			return true;
		}
		return false;
	}
	const bool rt_parser::try_get(const std::string& key, bool& value)
	{
		if (auto pair = m_data.find(key); pair != m_data.end()) {
			value = (pair->second == "1" ? true : false);
			return true;
		}
		return false;
	}
	const bool rt_parser::try_get(const std::string& key, const char* value)
	{
		if (auto pair = m_data.find(key); pair != m_data.end()) {
			value = pair->second.c_str();
			return true;
		}
		return false;
	}
}
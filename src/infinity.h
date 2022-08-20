#pragma once

namespace infinity
{
	enum UserListType
	{
		Kits = 1,
		Gender = 2,
		Race = 4, 
		Class = 8,
		Alignment = 16,
		RacialEnemy = 32,
		NumAttacks = 64,
		Profs = 128,
		Affects = 256
	};

	// Represents different games supported by infinity.
	struct Profile
	{
		// Common name [Baldur's Gate, Icewind Dale, Icewind Dale 2]
		const std::string name;
		// Game executable [BGMain.exe, IDMain.exe, iwd2.exe]
		const std::string executable;
		// Save game file name [Baldur, ??, icewind2]
		const std::string save_prefix;
		// Flags indicating which user list types to load
		const int user_lists;

		Profile(const std::string& name, const std::string& executable, const std::string& save_prefix,
			int user_lists) : name(name), executable(executable), save_prefix(save_prefix), user_lists(user_lists) { }
	};

	extern const Profile active_profile;
}
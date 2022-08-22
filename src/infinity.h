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
		const CString name;
		// Game executable [BGMain.exe, IDMain.exe, iwd2.exe]
		const CString executable;
		// Save game file name [Baldur, ??, icewind2]
		const CString save_prefix;
		// Color palette BMP 
		const CString palette;
		// Flags indicating which user list types to load
		const int user_lists;

		Profile(const CString& name, const CString& executable, const CString& save_prefix,
			const CString& palette, int user_lists)
			: name(name), executable(executable), save_prefix(save_prefix), palette(palette), user_lists(user_lists) { }
	};

	extern const Profile active_profile;
}
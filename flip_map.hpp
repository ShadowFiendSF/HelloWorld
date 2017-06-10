/*
This was used for filp the map key vs value.
And this was was a free function.
*/

#ifndef FLIP_MAP
#define FLIP_MAP
#include <map>
#include <vector>
#include <iostream>
template<typename K, typename T> using map_type = std::map<K, std::vector<T>>;
template<typename K, typename T>
map_type<K, T>& flip_map(const map_type<K, T>& origin, map_type<K, T>& filp_map)
{
	typedef typename map_type<K, T>::const_iterator map_iter_type;
	typedef typename std::vector<T>::const_iterator vec_iter_type;

	for(map_iter_type it = origin.cbegin(); it != origin.end(); ++it)
	{
		for(vec_iter_type vit = it->second.cbegin(); vit != it->second.end(); ++vit)
		{
			map_iter_type find_it = filp_map.find(*vit);
			if(find_it == filp_map.end())
			{
				filp_map[*vit] = std::vector<T>{it->first};
			}else{	
				filp_map[*vit].emplace_back(it->first);
			}
				
		}
	}

	return filp_map;
}

#endif

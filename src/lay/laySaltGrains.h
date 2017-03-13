
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2017 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#ifndef HDR_laySaltGrains
#define HDR_laySaltGrains

#include "laySaltGrain.h"

#include <list>

namespace lay
{

/**
 *  @brief A class representing a collection of grains (packages)
 *  A collection can have child collections and grains (leafs).
 */
class LAY_PUBLIC SaltGrains
{
public:
  typedef std::list<SaltGrains> collections_type;
  typedef collections_type::const_iterator collection_iterator;
  typedef std::list<SaltGrain> grains_type;
  typedef grains_type::const_iterator grain_iterator;

  /**
   *  @brief Constructor: creates an empty collection
   */
  SaltGrains ();

  /**
   *  @brief Equality
   */
  bool operator== (const SaltGrains &other) const;

  /**
   *  @brief Inequality
   */
  bool operator!= (const SaltGrains &other) const
  {
    return !operator== (other);
  }

  /**
   *  @brief Gets the name of the grain collection
   *
   *  The name is either a plain name (a word) or a path into a collection.
   *  Name paths are formed using the "/" separator. "mycollection" is a plain name,
   *  while "mycollection/subcollection" is a collection within a collection.
   */
  const std::string &name () const
  {
    return m_name;
  }

  /**
   *  @brief Sets the name of the grain collection
   */
  void set_name (const std::string &p);

  /**
   *  @brief Gets the title of the grain collection
   *
   *  The title is a brief description that is shown in the title of the
   *  package manager.
   */
  const std::string &title () const
  {
    return m_title;
  }

  /**
   *  @brief Sets the title of the grain collection
   */
  void set_title (const std::string &t);

  /**
   *  @brief Gets the absolute file path of the installed grain
   *  This is the file path to the grain folder.
   */
  const std::string &path () const
  {
    return m_path;
  }

  /**
   *  @brief Sets the absolute file path of the installed grain
   */
  void set_path (const std::string &p);

  /**
   *  @brief Gets the collections which are members of this collection (begin iterator)
   */
  collection_iterator begin_collections () const
  {
    return m_collections.begin ();
  }

  /**
   *  @brief Gets the collections which are members of this collection (end iterator)
   */
  collection_iterator end_collections () const
  {
    return m_collections.begin ();
  }

  /**
   *  @brief Adds a collection to this collection
   */
  void add_collection (const SaltGrains &collection);

  /**
   *  @brief Removes the collection given by the collection iterator
   */
  void remove_collection (collection_iterator iter);

  /**
   *  @brief Gets the grains (leaf nodes) which are members of this collection (begin iterator)
   */
  grain_iterator begin_grains () const
  {
    return m_grains.begin ();
  }

  /**
   *  @brief Gets the grains (leaf nodes) which are members of this collection (end iterator)
   */
  grain_iterator end_grains () const
  {
    return m_grains.begin ();
  }

  /**
   *  @brief Adds a grain to this collection
   */
  void add_grain (const SaltGrain &grain);

  /**
   *  @brief Removes the grain given by the grain iterator
   */
  void remove_grain (grain_iterator iter);

  /**
   *  @brief Gets a value indicating whether the collection is empty
   */
  bool is_empty () const;

  /**
   *  @brief Scan grains from a given path
   *  This will scan the grains found within this path and return a collection containing
   *  the grains from this path.
   *  Sub-collections are created from folders which contain grains or sub-collections.
   */
  static SaltGrains from_path (const std::string &path);

private:
  std::string m_name;
  std::string m_title;
  std::string m_path;
  collections_type m_collections;
  grains_type m_grains;
};

}

#endif

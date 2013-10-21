/**********************************************************************
 *  Copyright (c) 2008-2013, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef RULESET_MODELOBJECTFILTERSTRINGATTRIBUTE_IMPL_HPP
#define RULESET_MODELOBJECTFILTERSTRINGATTRIBUTE_IMPL_HPP

#include <ruleset/RulesetAPI.hpp>
#include <ruleset/ModelObjectFilterAttribute_Impl.hpp>
#include <ruleset/RulesetEnums.hpp>

class QDomDocument;
class QDomElement;

namespace openstudio {
namespace ruleset {

class ModelObjectFilterStringAttribute;

namespace detail {

  class RULESET_API ModelObjectFilterStringAttribute_Impl : public ModelObjectFilterAttribute_Impl {

    Q_OBJECT;

   public:
    /** @name Constructors and Destructors */
    //@{

    ModelObjectFilterStringAttribute_Impl(const std::string& attributeName, 
                                          const RulesetStringPredicate& predicate, 
                                          const std::string& testValue);

    ModelObjectFilterStringAttribute_Impl(const std::string& attributeName, 
                                          const RulesetStringPredicate& predicate, 
                                          const std::string& testValue,
                                          const UUID& uuid, 
                                          const UUID& versionUUID);

    ModelObjectFilterStringAttribute_Impl(const QDomElement& element);
     
    virtual ~ModelObjectFilterStringAttribute_Impl() {}

    //@}
    /** @name Getters */
    //@{

    RulesetStringPredicate predicate() const;

    std::string testValue() const;

    //@}
    /** @name Setters */
    //@{

    //@}
    /** @name Serialization */
    //@{

    virtual std::string xmlElementName() const;

    virtual void writeValues(QDomDocument& doc, QDomElement& element) const;

    //@}
    /** @name Queries */
    //@{

    /** Equality as determined by deep comparison of data members. */
    virtual bool equivalentData(const RulesetObject& other) const;

    //@}
    /** @name Actions */
    //@{

     virtual bool check(model::ModelObject& modelObject) const;

    //@}

   private:
    REGISTER_LOGGER("Ruleset.ModelObjectFilterStringAttribute");

    RulesetStringPredicate m_predicate;
    std::string m_testValue;
  };

} // detail

} // ruleset
} // openstudio

#endif // RULESET_MODELOBJECTFILTERSTRINGATTRIBUTE_IMPL_HPP
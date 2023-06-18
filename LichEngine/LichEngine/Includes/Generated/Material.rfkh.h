#pragma once

#include "EntityMacros.h"

#include <Refureku/TypeInfo/Entity/EEntityKind.h>
#include <string>
#include <Refureku/Misc/CodeGenerationHelpers.h>
#include <Refureku/Misc/DisableWarningMacros.h>
#include <Refureku/TypeInfo/Functions/Method.h>
#include <Refureku/TypeInfo/Functions/StaticMethod.h>
#include <Refureku/TypeInfo/Variables/Field.h>
#include <Refureku/TypeInfo/Variables/StaticField.h>
#include <Refureku/TypeInfo/Archetypes/Enum.h>
#include <Refureku/TypeInfo/Archetypes/EnumValue.h>
#include <Refureku/TypeInfo/Variables/Variable.h>
#include <Refureku/TypeInfo/Functions/Function.h>
#include <Refureku/TypeInfo/Archetypes/Template/ClassTemplate.h>
#include <Refureku/TypeInfo/Archetypes/Template/ClassTemplateInstantiation.h>
#include <Refureku/TypeInfo/Archetypes/Template/ClassTemplateInstantiationRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/Template/TypeTemplateArgument.h>
#include <Refureku/TypeInfo/Archetypes/Template/NonTypeTemplateArgument.h>
#include <Refureku/TypeInfo/Archetypes/Template/TemplateTemplateArgument.h>


#define Resources_Material_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<Material, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, Material>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, Material>());\
else\
{\
childClass.setFieldsCapacity(13u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< Resources::Resource>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< Resources::Resource>()); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("m_bloom", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_bloom") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_bloom), &thisClass);\
field = childClass.addField("m_generateShadow", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_generateShadow") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_generateShadow), &thisClass);\
field = childClass.addField("m_useDiffuseTextForOpacity", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_useDiffuseTextForOpacity") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_useDiffuseTextForOpacity), &thisClass);\
field = childClass.addField("m_opacity", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_opacity") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_opacity), &thisClass);\
field = childClass.addField("m_metalness", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_metalness") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_metalness), &thisClass);\
field = childClass.addField("m_roughness", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_roughness") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_roughness), &thisClass);\
field = childClass.addField("m_albedo", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_albedo") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector4D>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_albedo), &thisClass);\
field = childClass.addField("m_pDiffuseMap", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_pDiffuseMap") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pDiffuseMap), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_1337018504686008468u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_1337018504686008468u_0);\
field = childClass.addField("m_pNormalMap", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_pNormalMap") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pNormalMap), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_1605692046549011135u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_1605692046549011135u_0);\
field = childClass.addField("m_pHeightMap", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_pHeightMap") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pHeightMap), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_3883833071176212863u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_3883833071176212863u_0);\
field = childClass.addField("m_pMetallicMap", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_pMetallicMap") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pMetallicMap), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_16658643677365385877u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_16658643677365385877u_0);\
field = childClass.addField("m_pRoughnessMap", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_pRoughnessMap") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pRoughnessMap), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_10238714530185647720u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_10238714530185647720u_0);\
field = childClass.addField("m_pAoMap", std::hash<std::string>()(std::string("c:@N@Resources@S@Material@FI@m_pAoMap") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pAoMap), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_723314500730970350u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_723314500730970350u_0);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(rfk::internal::CodeGenerationHelpers::registerChildClass<Resources::Resource, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define File_Material_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<Resources::Material>() noexcept;\



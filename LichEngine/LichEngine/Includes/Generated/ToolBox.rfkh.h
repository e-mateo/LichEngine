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


#define SubShapeContainer_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<SubShapeContainer, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, SubShapeContainer>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, SubShapeContainer>());\
else\
{\
childClass.setFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< std::vector<Resources::SubModel *>>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< std::vector<Resources::SubModel *>>()); \
}\
rfk::internal::CodeGenerationHelpers::registerChildClass<std::vector<Resources::SubModel *>, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define VectorContainer_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<VectorContainer<T>, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, VectorContainer<T>>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, VectorContainer<T>>());\
else\
{\
childClass.setFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< std::vector<T *>>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< std::vector<T *>>()); \
}\
rfk::internal::CodeGenerationHelpers::registerChildClass<std::vector<T *>, ChildClass>(childClass);\
}\
\
public: static rfk::ClassTemplateInstantiation const& staticGetArchetype() noexcept {\
static bool initialized = false;\
static rfk::ClassTemplateInstantiation type("VectorContainer",std::hash<std::string>()(std::string("c:@ST>1#T@VectorContainer") + rfk::internal::getTypename<VectorContainer<T>>()), sizeof(VectorContainer<T>), 1, *rfk::getArchetype<::VectorContainer>());\
if (!initialized) {\
initialized = true;\
static rfk::TypeTemplateArgument arg0(rfk::getType<T>());\
type.addTemplateArgument(arg0);\
type.setDirectParentsCapacity(1);\
type.addDirectParent(rfk::getArchetype<std::vector<T *>>(), static_cast<rfk::EAccessSpecifier>(1));\
VectorContainer<T>::_rfk_registerChildClass<VectorContainer<T>>(type);\
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<VectorContainer<T>>>(),new rfk::NonMemberFunction<rfk::SharedPtr<VectorContainer<T>>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<VectorContainer<T>>),rfk::EMethodFlags::Default, nullptr);\
type.addSharedInstantiator(defaultSharedInstantiator);\
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<VectorContainer<T>>>(),new rfk::NonMemberFunction<rfk::UniquePtr<VectorContainer<T>>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<VectorContainer<T>>),rfk::EMethodFlags::Default, nullptr);\
type.addUniqueInstantiator(defaultUniqueInstantiator);\
[[maybe_unused]] rfk::Method* method = nullptr; [[maybe_unused]] rfk::StaticMethod* staticMethod = nullptr;\
type.setMethodsCapacity(7u); type.setStaticMethodsCapacity(0u); \
method = type.addMethod("GetClassArchetype", std::hash<std::string>()(std::string("c:@ST>1#T@VectorContainer@F@GetClassArchetype#") + rfk::internal::getTypename<VectorContainer<T>>()), rfk::getType<const rfk::Archetype *>(), new rfk::MemberFunction<VectorContainer<T>, const rfk::Archetype *()>(static_cast<const rfk::Archetype *(VectorContainer<T>::*)()>(& VectorContainer<T>::GetClassArchetype)), static_cast<rfk::EMethodFlags>(17));\
method = type.addMethod("IsFundamentalData", std::hash<std::string>()(std::string("c:@ST>1#T@VectorContainer@F@IsFundamentalData#") + rfk::internal::getTypename<VectorContainer<T>>()), rfk::getType<bool>(), new rfk::MemberFunction<VectorContainer<T>, bool ()>(static_cast<bool (VectorContainer<T>::*)()>(& VectorContainer<T>::IsFundamentalData)), static_cast<rfk::EMethodFlags>(17));\
method = type.addMethod("IsPointer", std::hash<std::string>()(std::string("c:@ST>1#T@VectorContainer@F@IsPointer#") + rfk::internal::getTypename<VectorContainer<T>>()), rfk::getType<bool>(), new rfk::MemberFunction<VectorContainer<T>, bool ()>(static_cast<bool (VectorContainer<T>::*)()>(& VectorContainer<T>::IsPointer)), static_cast<rfk::EMethodFlags>(17));\
method = type.addMethod("GetDataIndexPointer", std::hash<std::string>()(std::string("c:@ST>1#T@VectorContainer@F@GetDataIndexPointer#I#") + rfk::internal::getTypename<VectorContainer<T>>()), rfk::getType<void *>(), new rfk::MemberFunction<VectorContainer<T>, void *(int)>(static_cast<void *(VectorContainer<T>::*)(int)>(& VectorContainer<T>::GetDataIndexPointer)), static_cast<rfk::EMethodFlags>(17));\
method->setParametersCapacity(1); \
method->addParameter("index", 0u, rfk::getType<int>());\
\
method = type.addMethod("GetSize", std::hash<std::string>()(std::string("c:@ST>1#T@VectorContainer@F@GetSize#") + rfk::internal::getTypename<VectorContainer<T>>()), rfk::getType<int>(), new rfk::MemberFunction<VectorContainer<T>, int ()>(static_cast<int (VectorContainer<T>::*)()>(& VectorContainer<T>::GetSize)), static_cast<rfk::EMethodFlags>(17));\
method = type.addMethod("AddObject", std::hash<std::string>()(std::string("c:@ST>1#T@VectorContainer@F@AddObject#") + rfk::internal::getTypename<VectorContainer<T>>()), rfk::getType<void>(), new rfk::MemberFunction<VectorContainer<T>, void ()>(static_cast<void (VectorContainer<T>::*)()>(& VectorContainer<T>::AddObject)), static_cast<rfk::EMethodFlags>(17));\
method = type.addMethod("RemoveObject", std::hash<std::string>()(std::string("c:@ST>1#T@VectorContainer@F@RemoveObject#") + rfk::internal::getTypename<VectorContainer<T>>()), rfk::getType<void>(), new rfk::MemberFunction<VectorContainer<T>, void ()>(static_cast<void (VectorContainer<T>::*)()>(& VectorContainer<T>::RemoveObject)), static_cast<rfk::EMethodFlags>(17));\
}\
return type; }\
\
private: static inline rfk::ClassTemplateInstantiationRegisterer const _rfk_registerer = staticGetArchetype(); rfk::internal::ForceGenerateSymbol<&_rfk_registerer> _rfk_forceRegister() = delete;\
\
)\


#define File_ToolBox_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<SubShapeContainer>() noexcept;\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<VectorContainer>() noexcept;\



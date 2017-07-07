#pragma once

#define RHETORIC_PROPERTY_NAME(name) name ## _
#define RHETORIC_GETTER_DECL(type, name) type name () const
#define RHETORIC_SETTER_DECL(type, name) void set_ ## name (const type & value)
#define RHETORIC_SETTER_TRIVIAL_DECL(type, name) void set_ ## name (type value)

#define RHETORIC_GETTER(type, name) \
RHETORIC_GETTER_DECL(type, name) { return RHETORIC_PROPERTY_NAME(name); }

#define RHETORIC_GETTER_WEAK(type, name) \
RHETORIC_GETTER_DECL(type, name) { return RHETORIC_PROPERTY_NAME(name).lock(); }

#define RHETORIC_SETTER(type, name) \
RHETORIC_SETTER_DECL(type, name) { RHETORIC_PROPERTY_NAME(name) = value; }

#define RHETORIC_SETTER_TRIVIAL(type, name) \
RHETORIC_SETTER_TRIVIAL_DECL(type, name) { RHETORIC_PROPERTY_NAME(name) = value; }

#define RHETORIC_ACCESSOR(type, name) \
RHETORIC_GETTER(type, name) \
RHETORIC_SETTER(type, name)

#define RHETORIC_ACCESSOR_TRIVIAL(type, name) \
RHETORIC_GETTER(type, name) \
RHETORIC_SETTER_TRIVIAL(type, name)

#define RHETORIC_ACCESSOR_WEAK(type, name) \
RHETORIC_GETTER_WEAK(type, name) \
RHETORIC_SETTER(type, name)

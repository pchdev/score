#pragma once

#include <eggs/variant/variant.hpp>
#include <QString>
#include <State/Address.hpp>
#include <State/Value.hpp>

namespace State
{
struct ISCORE_LIB_STATE_EXPORT AddressAccessor
{
        State::Address address;
        std::vector<unsigned int> accessors;

        // Utility
        QString toString() const;

        bool operator==(const AddressAccessor& other) const
        {
            return address == other.address && accessors == other.accessors;
        }
        bool operator!=(const AddressAccessor& a) const
        {
            return !(*this == a);
        }
};

using RelationMember = eggs::variant<
    State::Address,
    State::AddressAccessor,
    State::Value>;

struct ISCORE_LIB_STATE_EXPORT Relation
{
        enum Operator {
            Equal,
            Different,
            Greater,
            Lower,
            GreaterEqual,
            LowerEqual,
            None
        } ;

        RelationMember lhs;
        Operator op;
        RelationMember rhs;

        friend bool operator==(const Relation& eq_lhs, const Relation& eq_rhs)
        {
            return eq_lhs.lhs == eq_rhs.lhs && eq_lhs.rhs == eq_rhs.rhs && eq_lhs.op == eq_rhs.op;
        }

        QString relMemberToString(RelationMember) const;
        QString toString() const;
};

struct ISCORE_LIB_STATE_EXPORT Pulse
{
        State::Address address;

        friend bool operator==(const Pulse& lhs, const Pulse& rhs)
        {
            return lhs.address == rhs.address;
        }

        QString toString() const;
};

ISCORE_LIB_STATE_EXPORT const QMap<State::Relation::Operator, QString> opToString();

}

using Comparator = State::Relation::Operator;

#pragma once
#include <iscore/tools/NamedObject.hpp>
#include <iscore/tools/SettableIdentifier.hpp>
#include <ProcessInterface/ZoomHelper.hpp>

class ProcessModel;
class ProcessViewModelInterface;
namespace iscore
{
    class SerializableCommand;
}
class ProcessPresenterInterface : public NamedObject
{
        Q_OBJECT
    public:
        using NamedObject::NamedObject;
        virtual ~ProcessPresenterInterface() = default;

        virtual void setWidth(int width) = 0;
        virtual void setHeight(int height) = 0;

        virtual void putToFront() = 0;
        virtual void putBehind() = 0;

        virtual void on_zoomRatioChanged(ZoomRatio) = 0;
        virtual void parentGeometryChanged() = 0;

        virtual const id_type<ProcessViewModelInterface>& viewModelId() const = 0;
        virtual const id_type<ProcessModel>& modelId() const = 0;
};

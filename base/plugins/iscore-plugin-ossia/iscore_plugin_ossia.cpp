#include "iscore_plugin_ossia.hpp"
#include "OSSIAControl.hpp"

#include <Protocols/MIDI/MIDIProtocolFactory.hpp>
#include <Protocols/Minuit/MinuitProtocolFactory.hpp>
#include <Protocols/OSC/OSCProtocolFactory.hpp>

#include "DocumentPlugin/ContextMenu/PlayContextMenuFactory.hpp"

iscore_plugin_ossia::iscore_plugin_ossia() :
    QObject {}
{
}

iscore::PluginControlInterface* iscore_plugin_ossia::make_control(iscore::Presenter* pres)
{
    return new OSSIAControl{pres};
}



std::vector<iscore::FactoryInterface*> iscore_plugin_ossia::factories(const QString& factoryName)
{
    if(factoryName == ProtocolFactory::factoryName())
    {
        return {//new MIDIProtocolFactory,
                new MinuitProtocolFactory,
                new OSCProtocolFactory};
    }

    if(factoryName == ScenarioActionsFactory::factoryName())
    {
        return {new PlayContextMenuFactory};
    }

    return {};
}


QStringList iscore_plugin_ossia::required() const
{
    return {"Scenario"};
}

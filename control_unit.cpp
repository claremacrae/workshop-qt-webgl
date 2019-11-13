#include "control_unit.h"
#include <QVariant>

ControlUnit::ControlUnit(QObject *parent) : QObject(parent)
{
    m_speed = 0;
    m_incr_speed = 0.3f;

    m_battery = 100;

    startTimer(16);
}

void ControlUnit::timerEvent(QTimerEvent *event) {
    Q_UNUSED(event)

    setProperty("speed", m_speed + m_incr_speed);
    if (m_speed > 100 || m_speed < 0) {
        m_incr_speed = -m_incr_speed;
    }

    setProperty("battery", m_battery * 0.999f);
}

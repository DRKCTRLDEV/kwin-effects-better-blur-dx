/*
    SPDX-FileCopyrightText: 2010 Fredrik Höglund <fredrik@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "blur_config.h"
#include "blurconfig.h"

#include <KPluginFactory>
#include "kwineffects_interface.h"

namespace KWin
{

K_PLUGIN_CLASS(BlurEffectConfig)

BlurEffectConfig::BlurEffectConfig(QObject *parent, const KPluginMetaData &data)
    : KCModule(parent, data)
{
    ui.setupUi(widget());
    BlurConfig::instance("kwinrc");
    addConfig(BlurConfig::self(), widget());

    QFile about(":/effects/better_blur_dx/kcm/about.html");
    if (about.open(QIODevice::ReadOnly)) {
        const auto html = about.readAll()
            .replace("${version}", ABOUT_VERSION_STRING)
            .replace("${repo}", "https://github.com/xarblu/kwin-effects-better-blur-dx");
        ui.aboutText->setHtml(html);
    }

    setupContextualHelp();
    setupSliderSpinBoxSync();
}

BlurEffectConfig::~BlurEffectConfig()
{
}

void BlurEffectConfig::setContextualHelp(
    KContextualHelpButton *const contextualHelpButton,
    const QString &text,
    QWidget *const heightHintWidget
)
{
    contextualHelpButton->setContextualHelpText(text);
    if (heightHintWidget) {
        const auto ownHeightHint = contextualHelpButton->sizeHint().height();
        const auto otherHeightHint = heightHintWidget->sizeHint().height();
        if (ownHeightHint >= otherHeightHint) {
            contextualHelpButton->setHeightHintWidget(heightHintWidget);
        }
    }
}

void BlurEffectConfig::setupContextualHelp()
{
    setContextualHelp(
        ui.windowClassesContextualHelp,
        QStringLiteral("<p>Specify one window class per line.</p>") +
        QStringLiteral("<p>Use <code>$blank</code> to match empty window classes.<br/>") +
        QStringLiteral("Use <code>$$</code> for literal dollar sign.</p>"),
        ui.windowClassesBriefDescription
    );
}

void BlurEffectConfig::setupSliderSpinBoxSync()
{
    // Sync spinbox values with slider values on load
    ui.blurStrengthSpinBox->setValue(ui.kcfg_BlurStrength->value());
    ui.noiseStrengthSpinBox->setValue(ui.kcfg_NoiseStrength->value());
    ui.brightnessSpinBox->setValue(ui.kcfg_Brightness->value());
    ui.saturationSpinBox->setValue(ui.kcfg_Saturation->value());
    ui.contrastSpinBox->setValue(ui.kcfg_Contrast->value());
}

void BlurEffectConfig::save()
{
    KCModule::save();

    OrgKdeKwinEffectsInterface interface(QStringLiteral("org.kde.KWin"),
                                         QStringLiteral("/Effects"),
                                         QDBusConnection::sessionBus());

    interface.reconfigureEffect(QStringLiteral("better_blur_dx"));
}

} // namespace KWin

#include "blur_config.moc"

#include "moc_blur_config.cpp"

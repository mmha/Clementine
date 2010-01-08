#include "osd.h"

OSD::OSD(QSystemTrayIcon* tray_icon, QObject* parent)
  : QObject(parent),
    tray_icon_(tray_icon)
{
  Init();
}

void OSD::SongChanged(const Song &song) {
  QString summary(song.PrettyTitleWithArtist());
  QStringList message_parts;

  if (!song.album().isEmpty())
    message_parts << song.album();
  if (song.disc() > 0)
    message_parts << QString("Disc %1").arg(song.disc());
  if (song.track() > 0)
    message_parts << QString("Track %1").arg(song.track());

  ShowMessage(summary, message_parts.join(" "), "notification-audio-play");
}

void OSD::Paused() {
  ShowMessage("Tangerine", "Paused");
}

void OSD::Stopped() {
  ShowMessage("Tangerine", "Playlist finished");
}

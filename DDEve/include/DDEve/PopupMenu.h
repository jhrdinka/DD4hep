// $Id: LCDD.h 1117 2014-04-25 08:07:22Z markus.frank@cern.ch $
//====================================================================
//  AIDA Detector description implementation for LCD
//--------------------------------------------------------------------
//
//  Author     : M.Frank
//
//====================================================================
#ifndef DD4HEP_DDEVE_POPUPMENU_H
#define DD4HEP_DDEVE_POPUPMENU_H

// Framework include files
#include "DD4hep/Callback.h"
#include "TGMenu.h"

// C/C++ include files
#include <string>
#include <map>

// Forward declarations
class TGWindow;
/*
 *   DD4hep namespace declaration
 */
namespace DD4hep {

  /** @class PopupMenu  PopupMenu.h DDEve/PopupMenu.h
   *
   * @author  M.Frank
   * @version 1.0
   */
  class PopupMenu  {
  public:
    typedef std::map<int,Callback> Callbacks;
  protected:
    /// Callback map
    Callbacks m_calls;
    TGPopupMenu m_popup;
    int m_cmd;
  public:
    /// Standard constructor
    PopupMenu(const TGWindow *parent);
    /// Default destructor
    virtual ~PopupMenu();
    /// Handle menu items.
    void HandleMenu(int id);

    /// Access to implementation
    TGPopupMenu& menu()  {  return m_popup; }

    /// Add the menu to the menu bar
    virtual void Build(TGMenuBar* bar, int hints=kLHintsNormal);

    /// Add a menu separator to the menu.
    virtual void AddSeparator(TGMenuEntry* before = 0);
    /// Add a menu label to the menu.
    virtual void AddLabel(const char* s, const TGPicture* p = 0, TGMenuEntry* before = 0);
    /// Add a (cascading) popup menu to a popup menu.
    virtual void AddPopup(const char* s, TGPopupMenu* popup, TGMenuEntry* before = 0, const TGPicture* p = 0);
    /// Add a new popup menu entry with a callback
    virtual int AddEntry(const char* name, Callback cb, void* ud=0, const TGPicture* p=0, TGMenuEntry* before=0);
    /// Add a new popup menu entry with a callback
    template <typename T>
      int AddEntry(const char* name, T* ptr, void (T::*pmf)(TGMenuEntry*, void*), void* ud=0, const TGPicture* p=0, TGMenuEntry* before=0)  {
      return AddEntry(name, Callback(ptr).make(pmf), ud, p, before);
    }
    /// Check menu entry
    void CheckEntry(int id);
    /// Uncheck menu entry
    void UnCheckEntry(int id);
    /// Get check-value
    bool IsEntryChecked(int id);

    /// Public access to the popup menu using '->'
    TGPopupMenu* operator->() { return &m_popup; }
    /// Public access to the popup menu using '->'
    operator TGPopupMenu* () { return &m_popup; }

    ClassDef(PopupMenu,0);
  };


} /* End namespace DD4hep   */


#endif /* DD4HEP_DDEVE_POPUPMENU_H */

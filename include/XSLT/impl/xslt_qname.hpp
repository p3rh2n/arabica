#ifndef ARABICA_XSLT_QNAME_HPP
#define ARABICA_XSLT_QNAME_HPP

#include <XML/strings.hpp>

namespace Arabica
{
namespace XSLT
{

template<class string_type, class string_adaptor>
struct QName
{
  string_type prefix;
  string_type localName;
  string_type namespaceURI;
  string_type qname;

  QName(const string_type& p,
              const string_type& lN,
              const string_type& uri) :
    prefix(p),
    localName(lN),
    namespaceURI(uri),
    qname(p.empty() ? lN : (p + ":" + lN))
  {
  } // QName

  static QName create(const XML::QualifiedName<string_type>& qName)
  {
    if(qName.prefix().length() && qName.namespaceUri().empty())
      throw SAX::SAXException("Prefix " + qName.prefix() + " is not declared.");
    return QName(qName.prefix(), qName.localName(), qName.namespaceUri());
  } // create

  static QName create(const string_type& qName)
  {
    return create(qName, "");
  } // create

  static QName create(const string_type& qName, const string_type& namespaceURI)
  {
    if(!Arabica::XML::is_qname<string_adaptor>(qName))
      throw SAX::SAXException("Bad name : '" + qName + "'");

    static char COLON = Arabica::text::Unicode<char>::COLON;

    string_type prefix;
    string_type localName;

    size_t colon = qName.find(COLON);
     
    if(colon == string_type::npos) 
      localName = qName;
    else
    {
      prefix = qName.substr(0, colon);
     localName = qName.substr(colon+1);
    }
    return QName(prefix, localName, namespaceURI);
  } // create

  bool operator==(const QName& rhs) const
  {
    return (namespaceURI == rhs.namespaceURI) &&
           (localName == rhs.localName);
  } // operator==

  bool operator<(const QName& rhs) const
  {
    if(namespaceURI == rhs.namespaceURI)
      return localName < rhs.localName;
    return namespaceURI < rhs.namespaceURI;
  } // operator<
}; // struct QName



} // namespace XSLT
} // namespace Arabica
#endif
